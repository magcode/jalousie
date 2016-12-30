#include "J_down.h"

/* Add optional parameters for the state machine to begin()
 * Add extra initialization code
 */

J_down& J_down::begin(int pin_rd, int pin_rp) {
	// clang-format off

	// clang-format on

	  const static state_t state_table[] PROGMEM = {
	    /*           ON_ENTER  ON_LOOP    ON_EXIT  EVT_TIMER_SELBSTHALT  EVT_TIMER_SWITCHWAIT  EVT_TIMER_WAITTOSTOP  ELSE */
	    /* STEP1 */ ENT_STEP1,      -1, EXT_STEP1,                   -1,                STEP2,                   -1,   -1,
	    /* STEP2 */ ENT_STEP2,      -1, EXT_STEP2,                STEP3,                   -1,                   -1,   -1,
	    /* STEP3 */ ENT_STEP3,      -1, EXT_STEP3,                   -1,                   -1,                STEP4,   -1,
	    /* STEP4 */ ENT_STEP4,      -1, EXT_STEP4,                   -1,                   -1,                   -1,   -1,
	  };
	Machine::begin(state_table, ELSE);
	this->pin_rd = pin_rd; // Save the pins
	this->pin_rp = pin_rp;

	pinMode(pin_rd, OUTPUT); // Set the pin modes
	pinMode(pin_rp, OUTPUT);

	timer_selbsthalt.set(-1); // Initialize the timers
	timer_switchwait.set(-1);
	timer_duration.set(-1);
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
		return timer_duration.expired(this);
	}
	return 0;
}

/* Add C++ code for each action
 * This generates the 'output' for the state machine
 */

void J_down::action(int id) {
	switch (id) {
	case ENT_STEP1:
		Serial.println( "ENT_STEP1" );
		digitalWrite(pin_rd, HIGH);
		return;
	case EXT_STEP1:
		Serial.println( "EXT_STEP1" );
		return;
	case ENT_STEP2:
		Serial.println( "ENT_STEP2" );
		digitalWrite(pin_rp, HIGH);
		return;
	case EXT_STEP2:
		Serial.println( "EXT_STEP2" );
		digitalWrite(pin_rd, LOW);
		digitalWrite(pin_rp, LOW);
		return;
	case ENT_STEP3:
		// stoppen: kurz in andere Richtung
		Serial.println( "ENT_STEP3" );
		digitalWrite(pin_rd, LOW);
		digitalWrite(pin_rp, HIGH);
		return;
	case EXT_STEP3:
		return;
	}
}

J_down& J_down::automatic(int wait, int halt, int dur) {
	timer_selbsthalt.set(halt);
	timer_switchwait.set(wait);
	timer_duration.set(dur);
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

