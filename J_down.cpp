#include "J_down.h"

/* Add optional parameters for the state machine to begin()
 * Add extra initialization code
 */

J_down& J_down::begin(int pin_rd, int pin_rp) {
	// clang-format off

	// clang-format on

	  const static state_t state_table[] PROGMEM = {
	    /*           ON_ENTER  ON_LOOP    ON_EXIT  EVT_TIMER_SELBSTHALT  EVT_TIMER_SWITCHWAIT  EVT_TIMER_WAITTOSTOP  EVT_TIMER_STOPCOMMAND  EVT_TIMER_WAITAFTERSTOP EVT_TIMER_TURN       ELSE */
	    /* STEP1 */ ENT_STEP1,      -1,        -1,                   -1,                STEP2,                   -1,          -1,               -1,                     -1,                -1,
	    /* STEP2 */ ENT_STEP2,      -1, EXT_STEP2,                STEP3,                   -1,                   -1,          -1,               -1,                     -1,                -1,
	    /* STEP3 */ ENT_STEP3,      -1, EXT_STEP3,                   -1,                STEP4,                   -1,          -1,               -1,                     -1,                -1,
	    /* STEP4 */ ENT_STEP4,      -1, EXT_STEP4,                   -1,                   -1,                STEP5,          -1,               -1,                     -1,                -1,
		/* STEP5 */ ENT_STEP5,      -1, EXT_STEP5,                   -1,                   -1,                   -1,       STEP6,               -1,                     -1,                -1,
		/* STEP6 */ ENT_STEP6,      -1,        -1,                   -1,                   -1,                   -1,          -1,            STEP7,                     -1,                -1,
		/* STEP7 */ ENT_STEP7,      -1, EXT_STEP7,                   -1,                   -1,                   -1,          -1,               -1,                  STEP8,                -1,
		/* STEP8 */ ENT_STEP8,      -1,        -1,                   -1,                   -1,                   -1,          -1,               -1,                     -1,                -1,
	  };
	Machine::begin(state_table, ELSE);
	this->pin_rd = pin_rd; // Save the pins
	this->pin_rp = pin_rp;

	pinMode(pin_rd, OUTPUT); // Set the pin modes
	pinMode(pin_rp, OUTPUT);

	timer_selbsthalt.set(-1); // Initialize the timers
	timer_switchwait.set(-1);
	timer_driving_down.set(-1);
	timer_stop_command.set(-1);
	timer_turn.set(-1);
	return *this;
}

/* Add C++ code for each internally handled event (input) 
 * The code must return 1 to trigger the event
 */

int J_down::event(int id) {
	switch (id) {
	case EVT_TIMER_SELBSTHALT:
		return timer_selbsthalt.expired(this);
	case EVT_TIMER_SWITCHWAIT:
		return timer_switchwait.expired(this);
	case EVT_TIMER_WAITTOSTOP:
		return timer_driving_down.expired(this);
	case EVT_TIMER_STOPCOMMAND:
		return timer_stop_command.expired(this);
	case EVT_TIMER_WAITAFTERSTOP:
		return timer_waitafterstop.expired(this);
	case EVT_TIMER_TURN:
		return timer_turn.expired(this);
	}
	return 0;
}

/* Add C++ code for each action
 * This generates the 'output' for the state machine
 */

void J_down::action(int id) {
	switch (id) {
	case ENT_STEP1:
		Serial.println( "ENT_STEP1, preparing direction" );
		timer_switchwait.set(20);
		digitalWrite(pin_rd, HIGH);
		return;
	case ENT_STEP2:
		Serial.println( "ENT_STEP2, start driving down till self hold");
		timer_selbsthalt.set(100);
		digitalWrite(pin_rp, HIGH);
		return;
	case EXT_STEP2:
		Serial.println( "EXT_STEP2, self hold started, releasing switch");
		digitalWrite(pin_rp, LOW);
		return;
	case ENT_STEP3:
		Serial.println( "ENT_STEP3" );
		timer_switchwait.set(20);
		return;
	case EXT_STEP3:
		return;
	case ENT_STEP4:
		Serial.println( "ENT_STEP4, driving down" );
		timer_driving_down.set(400);
		digitalWrite(pin_rd, LOW);
		return;
	case ENT_STEP5:
		Serial.println( "ENT_STEP5, stop command" );
		timer_stop_command.set(100);
		digitalWrite(pin_rp, HIGH);
		return;
	case EXT_STEP5:
		Serial.println( "EXT_STEP5, stop command done" );
		digitalWrite(pin_rp, LOW);
		return;
	case ENT_STEP6:
		Serial.println( "ENT_STEP6, waiting after stop command" );
		timer_waitafterstop.set(100);
		return;
	case ENT_STEP7:
		Serial.println( "ENT_STEP7, turning" );
		timer_turn.set(300);
		digitalWrite(pin_rp, HIGH);
		return;
	case EXT_STEP7:
		Serial.println( "ENT_STEP7, turning done" );
		digitalWrite(pin_rp, LOW);
	}
}

J_down& J_down::automatic(int wait, int halt, int dur) {
	//timer_selbsthalt.set(halt);
	//timer_switchwait.set(wait);
	//timer_driving_down.set(dur);
	return *this;
}

/* Optionally override the default trigger() method
 * Control how your machine processes triggers
 */

J_down& J_down::trigger(int event) {
	Machine::trigger(event);
	return *this;
}

/* Optionally override the default state() method
 * Control what the machine returns when another process requests its state
 */

int J_down::state(void) {
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

J_down& J_down::trace(Stream & stream) {
	Machine::setTrace(&stream, atm_serial_debug::trace,
			"J_DOWN\0EVT_TIMER_SELBSTHALT\0EVT_TIMER_SWITCHWAIT\0ELSE\0STEP1\0STEP2\0STEP3\0STEP4");
	return *this;
}

