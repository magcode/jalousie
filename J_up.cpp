#include "J_up.h"
const char msgENT_OFF [] PROGMEM = "-idle";
const char msgENT_STEP1 [] PROGMEM = "-driving up till self hold";
const char msgEXT_STEP1 [] PROGMEM = "-self hold started, releasing power";
const char msgENT_STEP2 [] PROGMEM = "-driving up";
const char msgENT_STEP3 [] PROGMEM = "-preparing stop";
const char msgEXT_STEP3 [] PROGMEM = "-stop command";
const char msgEXT_STEP4 [] PROGMEM = "-stop command done, releasing power";
const char msgEXT_STEP5 [] PROGMEM = "-release direction relay";

  
J_up& J_up::begin(int pin_rd, int pin_rp) {
	  const static state_t state_table[] PROGMEM = {
	  /*           ON_ENTER  ON_LOOP    ON_EXIT  EVT_TIMER_SELBSTHALT  EVT_TIMER_SWITCHWAIT  EVT_TIMER_WAITTOSTOP  EVT_TIMER_STOPCOMMAND   EVT_ON      ELSE */
    /* IDLE  */   ENT_OFF,      -1,        -1,                   -1,                   -1,                   -1,          -1,            STEP1,      -1,
	  /* STEP1 */ ENT_STEP1,      -1, EXT_STEP1,                STEP2,                   -1,                   -1,          -1,               -1,      -1,
	  /* STEP2 */ ENT_STEP2,      -1, EXT_STEP2,                   -1,                   -1,                STEP3,          -1,               -1,      -1,
	  /* STEP3 */ ENT_STEP3,      -1, EXT_STEP3,                   -1,                STEP4,                   -1,          -1,               -1,      -1,
	  /* STEP4 */ ENT_STEP4,      -1, EXT_STEP4,                   -1,                   -1,                   -1,       STEP5,               -1,      -1,
		/* STEP5 */ ENT_STEP5,      -1, EXT_STEP5,                   -1,               ENT_OFF,                   -1,          -1,               -1,      -1,
	  };
	Machine::begin(state_table, ELSE);
	this->pin_rd = pin_rd;
	this->pin_rp = pin_rp;

	pinMode(pin_rd, OUTPUT);
	pinMode(pin_rp, OUTPUT);

	timer_selbsthalt.set(-1); // Initialize the timers
	timer_switchwait.set(-1);
	timer_driving_up.set(-1);
	timer_stop_command.set(-1);
	return *this;
}

/* Add C++ code for each internally handled event (input) 
 * The code must return 1 to trigger the event
 */

int J_up::event(int id) {
	switch (id) {
	case EVT_TIMER_SELBSTHALT:
		return timer_selbsthalt.expired(this);
	case EVT_TIMER_SWITCHWAIT:
		return timer_switchwait.expired(this);
	case EVT_TIMER_WAITTOSTOP:
		return timer_driving_up.expired(this);
	case EVT_TIMER_STOPCOMMAND:
		return timer_stop_command.expired(this);
	}
	return 0;
}

J_up& J_up::setchannel(char aChannel) {
	channel=aChannel;
	return *this;
}

J_up& J_up::configure(int givenTimeUp) {
	timeup = givenTimeUp;
	return *this;
}
/* Add C++ code for each action
 * This generates the 'output' for the state machine
 */

void J_up::action(int id) {
	switch (id) {
	case ENT_OFF:
		Serial.print(channel);
    Serial.println((const __FlashStringHelper *) msgENT_OFF);		
		return;
	case ENT_STEP1:
		Serial.print(channel);		
    Serial.println((const __FlashStringHelper *) msgENT_STEP1);
		timer_selbsthalt.set(timeSelbstHalt);
		digitalWrite(pin_rp, LOW);
		return;
	case EXT_STEP1:
		Serial.print(channel);
    Serial.println((const __FlashStringHelper *) msgEXT_STEP1);
		digitalWrite(pin_rp, HIGH);
		return;
	case ENT_STEP2:
		Serial.print(channel);
    Serial.println((const __FlashStringHelper *) msgENT_STEP2);	
		timer_driving_up.set(timeup);
		return;
	case ENT_STEP3:
		Serial.print(channel);
    Serial.println((const __FlashStringHelper *) msgENT_STEP3);
		timer_switchwait.set(timeSwitchWait);
		digitalWrite(pin_rd, LOW);
		return;
	case EXT_STEP3:
		Serial.print(channel);
    Serial.println((const __FlashStringHelper *) msgEXT_STEP3);		
		digitalWrite(pin_rp, LOW);
		return;
	case ENT_STEP4:
		timer_stop_command.set(timeStopCommand);
		return;
	case EXT_STEP4:
		Serial.print(channel);
		Serial.println((const __FlashStringHelper *) msgEXT_STEP4);
		digitalWrite(pin_rp, HIGH);
		return;
	case ENT_STEP5:
		timer_switchwait.set(timeSwitchWait);
		return;
	case EXT_STEP5:
		Serial.print(channel);
    Serial.println((const __FlashStringHelper *) msgEXT_STEP5);		
		digitalWrite(pin_rd, HIGH);
		return;
	}
}

/* Optionally override the default trigger() method
 * Control how your machine processes triggers
 */

J_up& J_up::trigger(int event) {
	Machine::trigger(event);
	return *this;
}

/* Optionally override the default state() method
 * Control what the machine returns when another process requests its state
 */

int J_up::state(void) {
	return Machine::state();
}

J_up& J_up::debug(char* aChar) {
    Serial.print("Up ");
    Serial.print(channel);
    Serial.println((const __FlashStringHelper *) aChar); 
}

J_up& J_up::trace(Stream & stream) {
	Machine::setTrace(&stream, atm_serial_debug::trace,
			"J_up\0EVT_TIMER_SELBSTHALT\0EVT_TIMER_SWITCHWAIT\0ELSE\0STEP1\0STEP2\0STEP3\0STEP4");
	return *this;
}

