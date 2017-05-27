#pragma once

#include "Automaton.h"

class J_up: public Machine {

public:
	enum {
		IDLE, STEP1, STEP2, STEP3, STEP4, STEP5, STEP6}; // STATES
	enum {
		EVT_TIMER_SELBSTHALT, EVT_TIMER_SWITCHWAIT, EVT_TIMER_WAITTOSTOP, EVT_TIMER_STOPCOMMAND, EVT_TIMER_SHORTDRIVE, EVT_ON, ELSE
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
  J_up& debug(char* aChar);
	enum {
		ENT_OFF, ENT_STEP1, EXT_STEP1, ENT_STEP2, EXT_STEP2, ENT_STEP3, EXT_STEP3, ENT_STEP4, EXT_STEP4, ENT_STEP5, EXT_STEP5, ENT_STEP6}; // ACTIONS
	int event(int id);
	void action(int id);
	int pin_rd, pin_rp;
	atm_timer_millis timer_selbsthalt, timer_switchwait, timer_driving_up, timer_stop_command, timer_driving_up_short;
	char channel;
	int timeup;
	int timeSwitchWait = 100;
	int timeStopCommand = 200;
	int timeSelbstHalt = 2600;
};
