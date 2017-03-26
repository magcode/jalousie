#include "J_up.h"

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

J_up& J_up::configure(int givenTimeDown) {
	timeup = givenTimeDown;
	return *this;
}
/* Add C++ code for each action
 * This generates the 'output' for the state machine
 */

void J_up::action(int id) {
	switch (id) {
	case ENT_OFF:
		Serial.print(channel);
		Serial.println( "ENT_OFF, idle" );
		return;
	case ENT_STEP1:
		Serial.print(channel);
		Serial.println( "ENT_STEP1, driving up till self hold" );
		timer_selbsthalt.set(timeSelbstHalt);
		digitalWrite(pin_rp, HIGH);
		return;
	case EXT_STEP1:
		Serial.print(channel);
		Serial.println( "EXT_STEP1, self hold started, releasing power");
		digitalWrite(pin_rp, LOW);
		return;
	case ENT_STEP2:
		Serial.print(channel);
		Serial.println( "ENT_STEP2, driving up");
		timer_driving_up.set(timeup);
		return;
	case ENT_STEP3:
		Serial.print(channel);
		Serial.println( "ENT_STEP3, preparing stop");
		timer_switchwait.set(timeSwitchWait);
		digitalWrite(pin_rd, HIGH);
		return;
	case EXT_STEP3:
		Serial.print(channel);
		Serial.println( "EXT_STEP3, stop command" );
		digitalWrite(pin_rp, HIGH);
		return;
	case ENT_STEP4:
		timer_stop_command.set(timeStopCommand);
		return;
	case EXT_STEP4:
		Serial.print(channel);
		Serial.println( "EXT_STEP4, stop command done, releasing power" );
		digitalWrite(pin_rp, LOW);
		return;
	case ENT_STEP5:
		timer_switchwait.set(timeSwitchWait);
		return;
	case EXT_STEP5:
		Serial.print(channel);
		Serial.println( "EXT_STEP5, release direction relay" );
		digitalWrite(pin_rd, LOW);
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

/* Nothing customizable below this line                          
 ************************************************************************************************
 */

/* Public event methods
 *
 */

/* State trace method
 * Sets the symbol table and the default logging method for serial monitoring
 */

J_up& J_up::trace(Stream & stream) {
	Machine::setTrace(&stream, atm_serial_debug::trace,
			"J_up\0EVT_TIMER_SELBSTHALT\0EVT_TIMER_SWITCHWAIT\0ELSE\0STEP1\0STEP2\0STEP3\0STEP4");
	return *this;
}
