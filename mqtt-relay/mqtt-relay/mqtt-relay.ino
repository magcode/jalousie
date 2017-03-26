#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 155, 89);
IPAddress server(192, 168, 155, 20);

EthernetClient ethClient;
PubSubClient client(ethClient);

// Number of Motors to control
#define NO_MOTOR 2

// state of the motors
int iMotorState[NO_MOTOR];
#define MOTOR_UP    -1
#define MOTOR_STOP   0
#define MOTOR_DOWN   1
#define MOTOR_INVAL -999

// time to wait when turning motor off or changing direction
// recommended to allow motor capacitor to unload over motor coil 
#define MOTOR_WAIT_MS 100

// time for direction relay to swtich before power is applied
// recommended to avoid implicit switch of direction with power on
#define RELAIS_WAIT_MS 100

// at which pin is motor 0's 1st pin? - A0 is pin 14, A1=15 ...
#define MOTOR_PIN_OFFSET 14
unsigned long ulMotorEventEnd[NO_MOTOR];  // end of current motor event

void callback(char* topic, byte* payload, unsigned int length) {
  // home/sz/rollo/2,1/down
  char paylC [length];
  String myString = String((char *) payload);
  myString.toCharArray(paylC, length+1);
  processCommand(topic, paylC);
}


// home/sz/rollo/2,1/down
void processCommand(char* topic, char* durationRaw) {
  Serial.print("topic: ");
  Serial.println(topic);
  Serial.print("duration: ");
  Serial.println(durationRaw);
  
  char delimiter[] = "/";
  char *ptr;
  int ii=0;

  char motorsP[8];
  char delimiterMotors[] = ",";
  
  int iCommand = MOTOR_INVAL;
  int iDur = atoi(durationRaw);
  
  ptr = strtok(topic, delimiter);    
  while(ptr != NULL) {
    if (ii==3) {
      // copy value of motor pointer into another variable 
      strcpy(motorsP,ptr);
    } else if (ii==4) {
      if (strcmp(ptr,"up") == 0) {
        iCommand = MOTOR_UP;
      } else if (strcmp(ptr,"down") == 0) {
        iCommand = MOTOR_DOWN;
      }
      Serial.print("command: "); Serial.println(iCommand); 
    } 
    ptr = strtok(NULL, delimiter);
    ii++;
  }

  // multiple motors?
  char* motors = strtok(motorsP, delimiterMotors);
  while(motors != NULL) {
    int iMotor = atoi(motors);
    SetMotor(iMotor,iCommand,iDur);
    motors = strtok(NULL, delimiterMotors);
  }
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("jalousiecontroller-sz")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("home/sz/rollo","I'm online");
      // ... and resubscribe
      client.subscribe("home/sz/rollo/+/up");
      client.subscribe("home/sz/rollo/+/down");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(57600);

  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  checkRunningCommands();
}

void checkRunningCommands()
{
  //////////////////////////////////////////
  // check for end timestamp of motor events
  //////////////////////////////////////////
  for (int ii=0;ii<NO_MOTOR;ii++)
  {
    if (ulMotorEventEnd[ii]<millis())
    {   
      // stop motor if required
      if (iMotorState[ii]!=MOTOR_STOP)
      {
        SetMotor(ii+1,MOTOR_STOP,0);
      }
    }
  }
}


///////////////////////////////////////
// sets a motor into up/down/stop state
///////////////////////////////////////
void SetMotor(int iMotor, int iState, int iDuration)
{ 
  // calculate output pins
  int iMotorPwr=2*iMotor   +MOTOR_PIN_OFFSET;
  int iMotorDir=2*iMotor+1 +MOTOR_PIN_OFFSET;
  int iMotorStateIndex = iMotor - 1;
  
  // define output state
  pinMode(iMotorPwr,OUTPUT); 
  pinMode(iMotorDir,OUTPUT); 
  
  Serial.print("Current state of motor ");
  Serial.print(iMotor);
  Serial.print(":");
  Serial.println(String(iMotorState[iMotorStateIndex]));
  
  // pin n is motor power; pin n+1 is motor direction for motor 0; etc...
  // relais board INVERTS!!! - HIGH = OFF
  if (iState==MOTOR_STOP)
  {
    digitalWrite(iMotorPwr,HIGH);
    delay(MOTOR_WAIT_MS); // wait some time to allow motor capacitor to unload over motor coil
    digitalWrite(iMotorDir,HIGH);
    ulMotorEventEnd[iMotorStateIndex]=millis(); 
    iMotorState[iMotorStateIndex]=MOTOR_STOP;
    Serial.print("Send Motor STOP command for motor: ");
    Serial.println(iMotor);
  }
  else if (iState==MOTOR_UP)
  {
    // if still driving, stop first (incl delay)
    if (iMotorState[iMotor-1]!=MOTOR_STOP) {
      SetMotor(iMotor,MOTOR_STOP,0);
    } else {
      digitalWrite(iMotorDir,HIGH);
      delay(RELAIS_WAIT_MS);
      digitalWrite(iMotorPwr,LOW);
      ulMotorEventEnd[iMotor-1]=millis()+iDuration;
      Serial.print("new ulMotorEventEnd: ");
      Serial.println(ulMotorEventEnd[iMotorStateIndex]);
      iMotorState[iMotorStateIndex]=iState;
      Serial.print("Send Motor UP command for motor: ");
      Serial.println(iMotor);
    }
  }
  else if (iState==MOTOR_DOWN)
  {
    // if still driving, stop first 
    if (iMotorState[iMotor-1]!=MOTOR_STOP) {
      SetMotor(iMotor,MOTOR_STOP,0);
    } else {
      digitalWrite(iMotorDir,LOW);
      delay(RELAIS_WAIT_MS);
      digitalWrite(iMotorPwr,LOW);
      ulMotorEventEnd[iMotorStateIndex]=millis()+iDuration;
      iMotorState[iMotorStateIndex]=iState;
      Serial.print("Send Motor DOWN command for motor: ");
      Serial.println(iMotor);
    }
  }
}
