#include "Automaton.h"
#include "J_down.h"
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 155, 89);
IPAddress server(192, 168, 155, 20);

EthernetClient ethClient;
PubSubClient client(ethClient);

#define MOTOR_UP    -1
#define MOTOR_STOP   0
#define MOTOR_DOWN   1
#define MOTOR_INVAL -999



J_down* J_downs[4]; 


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
  
  int iCommand = -1;
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
      } else if (strcmp(ptr,"stop") == 0) {
        iCommand = MOTOR_STOP;
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
    iMotor = iMotor - 1;
    if (iCommand==MOTOR_DOWN) {
      J_downs[iMotor]->configure(3000, iDur);
      J_downs[iMotor]->trigger( J_downs[iMotor]->EVT_ON );
    } else if (iCommand==MOTOR_STOP) {
      //J_down1.trigger( J_down1.EVT_STOP );
    }
    
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
      client.subscribe("home/sz/rollo/+/stop");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {

	  Serial.begin(57600);
	  Serial.println( "Started" );
    
  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
  /*
	  Atm_digital buttonDown1;
	  Atm_digital buttonUp1;
	  Atm_digital buttonStop2;

	  Atm_digital buttonDown2;
	  Atm_digital buttonUp2;
	  //simulation 5ms press -> start
	  //buttonDown1.begin( 2, 5 ).onChange( J_down1, J_down1.EVT_ON );

	  buttonStop2.begin( 1, 5 ).onChange( J_down2, J_down2.EVT_STOP );
	  buttonDown2.begin( 3, 5 ).onChange( J_down2, J_down2.EVT_ON );
	  buttonDown1.begin( 2, 5 ).onChange( J_down2.configure(0, 0) );


	  //buttonStop2.begin( 1, 5 ).onChange( J_down2, J_down2.EVT_ON );
*/


J_downs[0] = new J_down();
J_downs[1] = new J_down();

    J_downs[0]->begin(14, 15).setchannel('1');
    J_downs[1]->begin(16, 17).setchannel('2');
    //J_down2.begin(16, 17).setchannel('2').configure(3000, 500);

}

void loop() {
	automaton.run();

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
