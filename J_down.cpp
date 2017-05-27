#include "J_down.h"
const char msgENT_OFF [] PROGMEM = "-idle";
const char msgENT_STEP1 [] PROGMEM = "-preparing direction";
const char msgENT_STEP2_1 [] PROGMEM = "-drive till self hold";
const char msgENT_STEP2_2 [] PROGMEM = "-short drive";
const char msgEXT_STEP2 [] PROGMEM = "-self hold started, release power";
const char msgENT_STEP3 [] PROGMEM = "-wait before release direction";
const char msgEXT_STEP3 [] PROGMEM = "-release direction";
const char msgENT_STEP4 [] PROGMEM = "-driving down";
const char msgENT_STEP5_1 [] PROGMEM = "-stop command";
const char msgENT_STEP5_2 [] PROGMEM = "-no stop command";
const char msgEXT_STEP5 [] PROGMEM = "-stop command done";
const char msgENT_STEP6 [] PROGMEM = "-waiting after stop";
const char msgENT_STEP7_1 [] PROGMEM = "-turning";
const char msgENT_STEP7_2 [] PROGMEM = "-not turning";
const char msgEXT_STEP7 [] PROGMEM = "-turning done";

J_down& J_down::begin(int pin_rd, int pin_rp) {
	  const static state_t state_table[] PROGMEM = {
    /*           ON_ENTER  ON_LOOP    ON_EXIT  EVT_TIMER_SELBSTHALT  EVT_TIMER_SWITCHWAIT  EVT_TIMER_WAITTOSTOP  EVT_TIMER_STOPCOMMAND  EVT_TIMER_WAITAFTERSTOP EVT_TIMER_TURN  EVT_ON      EVT_STOP    ELSE */
    /* IDLE  */   ENT_OFF,      -1,        -1,                   -1,                   -1,                   -1,          -1,               -1,                     -1,          STEP1,        -1,       -1,
	  /* STEP1 */ ENT_STEP1,      -1,        -1,                   -1,                STEP2,                   -1,          -1,               -1,                     -1,             -1,        -1,       -1,
	  /* STEP2 */ ENT_STEP2,      -1, EXT_STEP2,                STEP3,                   -1,                   -1,          -1,               -1,                     -1,             -1,        -1,       -1,
	  /* STEP3 */ ENT_STEP3,      -1, EXT_STEP3,                   -1,                STEP4,                   -1,          -1,               -1,                     -1,             -1,        -1,       -1,
	  /* STEP4 */ ENT_STEP4,      -1, EXT_STEP4,                   -1,                   -1,                STEP5,          -1,               -1,                     -1,             -1,     STEP5,       -1,
		/* STEP5 */ ENT_STEP5,      -1, EXT_STEP5,                   -1,                   -1,                   -1,       STEP6,               -1,                     -1,             -1,        -1,       -1,
		/* STEP6 */ ENT_STEP6,      -1,        -1,                   -1,                   -1,                   -1,          -1,            STEP7,                     -1,             -1,        -1,       -1,
		/* STEP7 */ ENT_STEP7,      -1, EXT_STEP7,                   -1,                   -1,                   -1,          -1,               -1,                   IDLE,             -1,        -1,       -1
	  };
	Machine::begin(state_table, ELSE);
	this->pin_rd = pin_rd;
	this->pin_rp = pin_rp;

	pinMode(pin_rd, OUTPUT);
	pinMode(pin_rp, OUTPUT);
  digitalWrite(pin_rd, HIGH);
  digitalWrite(pin_rp, HIGH);
  
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

J_down& J_down::setchannel(char aChannel) {
	channel=aChannel;
	return *this;
}

J_down& J_down::configure(int givenTimeDown, int givenTimeTurn) {
	timedown = givenTimeDown;
	timeturn = givenTimeTurn;
	return *this;
}
/* Add C++ code for each action
 * This generates the 'output' for the state machine
 */

void J_down::action(int id) {
	switch (id) {
	case ENT_OFF:
    debug(msgENT_OFF);
		return;
	case ENT_STEP1:
    debug(msgENT_STEP1);
		timer_switchwait.set(timeSwitchWait);
		digitalWrite(pin_rd, LOW);
		return;
	case ENT_STEP2:
    if (timedown > timeSelbstHalt)
    {
      debug(msgENT_STEP2_1);
      timer_selbsthalt.set(timeSelbstHalt);
      digitalWrite(pin_rp, LOW);
    } else {
      debug(msgENT_STEP2_2);
      timer_selbsthalt.set(timedown);
      digitalWrite(pin_rp, LOW);
    }
		return;
	case EXT_STEP2:
    debug(msgEXT_STEP2);
		digitalWrite(pin_rp, HIGH);
		return;
	case ENT_STEP3:
    debug(msgENT_STEP3);
		timer_switchwait.set(timeSwitchWait);
		return;
	case EXT_STEP3:
    debug(msgEXT_STEP3);
		digitalWrite(pin_rd, HIGH);
		return;
	case ENT_STEP4:
    debug(msgENT_STEP4);
		timer_driving_down.set(timedown-timeSelbstHalt);
		return;
	case ENT_STEP5:
    if (timedown > timeSelbstHalt) {
      debug(msgENT_STEP5_1);
		  timer_stop_command.set(timeStopCommand);
      digitalWrite(pin_rp, LOW);
    } else {
      debug(msgENT_STEP5_2);
      timer_stop_command.set(0);      
    }		
		return;
	case EXT_STEP5:
    debug(msgEXT_STEP5);
		digitalWrite(pin_rp, HIGH);
		return;
	case ENT_STEP6:
    debug(msgENT_STEP6);
		timer_waitafterstop.set(timeWaitAfterStop);
		return;
	case ENT_STEP7:
		if (timeturn >0)
		{
      debug(msgENT_STEP7_1);
			timer_turn.set(timeturn);
			digitalWrite(pin_rp, LOW);
		} else {
      debug(msgENT_STEP7_2);
			timer_turn.set(0);
		}
		return;
	case EXT_STEP7:
    debug(msgEXT_STEP7);
		digitalWrite(pin_rp, HIGH);
	}
}

/* Optionally override the default trigger() method
 * Control how your machine processes triggers
 */

J_down& J_down::trigger(int event) {
	Machine::trigger(event);
	return *this;
}

J_down& J_down::debug(char* aChar) {
    Serial.print("Down ");
    Serial.print(channel);
    Serial.println((const __FlashStringHelper *) aChar); 
}

int J_down::state(void) {
	return Machine::state();
}

J_down& J_down::trace(Stream & stream) {
	Machine::setTrace(&stream, atm_serial_debug::trace,
			"J_DOWN\0EVT_TIMER_SELBSTHALT\0EVT_TIMER_SWITCHWAIT\0ELSE\0STEP1\0STEP2\0STEP3\0STEP4");
	return *this;
}

