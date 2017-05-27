#include "Automaton.h"
#include "J_down.h"
#include "J_up.h"
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <avr/pgmspace.h>

const char msgAttemtMQTT[] PROGMEM = "Attempting MQTT connection...";
const char msgConnectedMQTT[] PROGMEM = "Connected to MQTT.";
const char msgRetryMQTT[] PROGMEM = "trying again in 5 seconds...";
const char msgStarted[] PROGMEM = "Started";
const char msgIgnore[] PROGMEM = "ignoring this request";

byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 155, 89);
IPAddress server(192, 168, 155, 20);

EthernetClient ethClient;
PubSubClient client(ethClient);

J_down* J_downs[4]; 
J_up* J_ups[4];

void callback(char* topic, byte* payload, unsigned int length) {
  // convert byte array into char array
  char paylC [length+1];
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    paylC[i] = (char)payload[i];
  }
  paylC[length] = '\0';

  processCommand(topic, paylC);
}

// executes the command
// e.g. topic = home/sz/rollo/2,1/down
//      durationRaw = 10000,1500
void processCommand(char* topic, char* durationRaw) {
  //Serial.print("topic: ");
  Serial.println(topic);
  //Serial.print("duration: ");
  Serial.println(durationRaw);
  
  char delimiter[] = "/";
  char *ptr;
  int ii=0;

  char motorsP[8];
  char delimiterMotors[] = ",";
  
  int iCommand = 0;
  int iDurDrive = 0;
  int iDurTurn = 0;

  // split the full incoming mqtt message
  ptr = strtok(topic, delimiter);    
  while(ptr != NULL) {
    if (ii==3) {
      // copy value of motor pointer into another variable 
      strcpy(motorsP,ptr);
    } else if (ii==4) {
      if (strcmp(ptr,"up") == 0) {
        iCommand = -1;
      } else if (strcmp(ptr,"down") == 0) {
        iCommand = 1;
      } else if (strcmp(ptr,"stop") == 0) {
        iCommand = 0;
      }
      Serial.print("command: "); Serial.println(iCommand); 
    } 
    ptr = strtok(NULL, delimiter);
    ii++;
  }

  // split payload
  // payload is defined as <time for up/down>,<time for turning>
  char* payloads = strtok(durationRaw, delimiterMotors);
  ii=0;
  while(payloads != NULL) {
    if (ii==0) {
      iDurDrive = atoi(payloads);
      Serial.print("dur1: "); Serial.println(payloads); 
    } else if (ii==1) {
      iDurTurn = atoi(payloads);
      Serial.print("dur2: "); Serial.println(payloads); 
    }
    payloads = strtok(NULL, delimiterMotors);
    ii++;    
  }
  
  // split the motor definition. Do we have multiple motors?
  char* motors = strtok(motorsP, delimiterMotors);
  while(motors != NULL) {
    int iMotor = atoi(motors);
    iMotor = iMotor - 1;
    if (iCommand==1) {
      J_downs[iMotor]->configure(iDurDrive, iDurTurn);
      J_downs[iMotor]->trigger( J_downs[iMotor]->EVT_ON );
    } else if (iCommand==0) {
      //J_down1.trigger( J_down1.EVT_STOP );
    } else if (iCommand==-1) {
      if (J_downs[iMotor]->state() == 0) {
        J_ups[iMotor]->configure(iDurDrive);
        J_ups[iMotor]->trigger( J_ups[iMotor]->EVT_ON );
      } else {
        Serial.print((const __FlashStringHelper *) msgIgnore);
      }       
    }
    motors = strtok(NULL, delimiterMotors);
  }

   Serial.print("free RAM: ");Serial.println(freeRam ());
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println((const __FlashStringHelper *) msgAttemtMQTT);
    // Attempt to connect
    if (client.connect("jalousiecontroller-sz")) {
      Serial.println((const __FlashStringHelper *) msgConnectedMQTT);
      // Once connected, publish an announcement...
      client.publish("home/sz/rollo","I'm online");
      // ... and resubscribe
      client.subscribe("home/sz/rollo/+/up");
      client.subscribe("home/sz/rollo/+/down");
      client.subscribe("home/sz/rollo/+/stop");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.print((const __FlashStringHelper *) msgRetryMQTT);
      
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(57600);
	Serial.println((const __FlashStringHelper *) msgStarted);
  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
  
  J_downs[0] = new J_down();
  J_downs[1] = new J_down();
  J_downs[2] = new J_down();
  J_downs[3] = new J_down();

  J_ups[0] = new J_up();
  J_ups[1] = new J_up();
  J_ups[2] = new J_up();
  J_ups[3] = new J_up();
  
  J_downs[0]->begin(14, 15).setchannel('1');
  J_downs[1]->begin(16, 17).setchannel('2');
  J_downs[2]->begin(18, 19).setchannel('3');
  J_downs[3]->begin(2, 3).setchannel('4');

  J_ups[0]->begin(14, 15).setchannel('1');
  J_ups[1]->begin(16, 17).setchannel('2');
  J_ups[2]->begin(18, 19).setchannel('3');
  J_ups[3]->begin(2, 3).setchannel('4');
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

	automaton.run();
}
