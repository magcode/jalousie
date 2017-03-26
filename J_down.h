#pragma once

#include "Automaton.h"

class J_down: public Machine {

public:
	enum {
		IDLE, STEP1, STEP2, STEP3, STEP4, STEP5, STEP6, STEP7
	}; // STATES
	enum {
		EVT_TIMER_SELBSTHALT, EVT_TIMER_SWITCHWAIT, EVT_TIMER_WAITTOSTOP, EVT_TIMER_STOPCOMMAND, EVT_TIMER_WAITAFTERSTOP, EVT_TIMER_TURN, EVT_ON, EVT_STOP, ELSE
	}; // EVENTS
	J_down(void) :
			Machine() {
	}
	;
	J_down& begin(void);
	J_down& trace(Stream & stream);
	J_down& trigger(int event);
	int state(void);
	J_down& begin(int pin_rd, int pin_rp);
	J_down& setchannel(char channel);
	J_down& configure(int timedown, int timeturn);

private:
	enum {
		ENT_OFF, ENT_STEP1, EXT_STEP1, ENT_STEP2, EXT_STEP2, ENT_STEP3, EXT_STEP3, ENT_STEP4, EXT_STEP4, ENT_STEP5, EXT_STEP5, ENT_STEP6, ENT_STEP7, EXT_STEP7
	}; // ACTIONS
	int event(int id);
	void action(int id);
	int pin_rd, pin_rp;
	atm_timer_millis timer_selbsthalt, timer_switchwait, timer_driving_down, timer_stop_command, timer_waitafterstop, timer_turn;
	char channel;
	int timedown;
	int timeturn;
	int timeSwitchWait = 20;
	int timeStopCommand = 100;
	int timeWaitAfterStop = 100;
	int timeSelbstHalt = 100;
};
