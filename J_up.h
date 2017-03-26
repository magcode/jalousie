#pragma once

#include "Automaton.h"

class J_up: public Machine {

public:
	enum {
		IDLE, STEP1, STEP2, STEP3, STEP4, STEP5, STEP6, STEP7
	}; // STATES
	enum {
		EVT_TIMER_SELBSTHALT, EVT_TIMER_SWITCHWAIT, EVT_TIMER_WAITTOSTOP, EVT_TIMER_STOPCOMMAND, EVT_ON, ELSE
	}; // EVENTS
	J_up(void) :
			Machine() {
	}
	;
	J_up& begin(void);
	J_up& trace(Stream & stream);
	J_up& trigger(int event);
	int state(void);
	J_up& begin(int pin_rd, int pin_rp);
	J_up& setchannel(char channel);
	J_up& configure(int timeup);

private:
	enum {
		ENT_OFF, ENT_STEP1, EXT_STEP1, ENT_STEP2, EXT_STEP2, ENT_STEP3, EXT_STEP3, ENT_STEP4, EXT_STEP4, ENT_STEP5, EXT_STEP5, ENT_STEP6, ENT_STEP7, EXT_STEP7
	}; // ACTIONS
	int event(int id);
	void action(int id);
	int pin_rd, pin_rp;
	atm_timer_millis timer_selbsthalt, timer_switchwait, timer_driving_up, timer_stop_command;
	char channel;
	int timeup;
	int timeSwitchWait = 20;
	int timeStopCommand = 100;
	int timeSelbstHalt = 100;
};
