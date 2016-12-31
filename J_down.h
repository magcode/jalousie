#pragma once

#include "Automaton.h"

class J_down: public Machine {

public:
	enum {
		STEP1, STEP2, STEP3, STEP4, STEP5, STEP6, STEP7, STEP8
	}; // STATES
	enum {
		EVT_TIMER_SELBSTHALT, EVT_TIMER_SWITCHWAIT, EVT_TIMER_WAITTOSTOP, EVT_TIMER_STOPCOMMAND, EVT_TIMER_WAITAFTERSTOP, EVT_TIMER_TURN, ELSE
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
	J_down& automatic(int wait, int halt, int dur);

private:
	enum {
		ENT_STEP1, EXT_STEP1, ENT_STEP2, EXT_STEP2, ENT_STEP3, EXT_STEP3, ENT_STEP4, EXT_STEP4, ENT_STEP5, EXT_STEP5, ENT_STEP6, ENT_STEP7, EXT_STEP7, ENT_STEP8
	}; // ACTIONS
	int event(int id);
	void action(int id);
	int pin_rd, pin_rp;
	atm_timer_millis timer_selbsthalt, timer_switchwait, timer_driving_down, timer_stop_command, timer_waitafterstop, timer_turn;

};

/*
 Automaton::ATML::begin - Automaton Markup Language

 <?xml version="1.0" encoding="UTF-8"?>
 <machines>
 <machine name="J_down">
 <states>
 <STEP1 index="0" on_enter="ENT_STEP1" on_exit="EXT_STEP1">
 <EVT_TIMER_SWITCHWAIT>STEP2</EVT_TIMER_SWITCHWAIT>
 </STEP1>
 <STEP2 index="1" on_enter="ENT_STEP2" on_exit="EXT_STEP2">
 <EVT_TIMER_SELBSTHALT>STEP3</EVT_TIMER_SELBSTHALT>
 </STEP2>
 <STEP3 index="2" on_enter="ENT_STEP3" on_exit="EXT_STEP3">
 <EVT_TIMER_SWITCHWAIT>STEP4</EVT_TIMER_SWITCHWAIT>
 </STEP3>
 <STEP4 index="3">
 </STEP4>
 </states>
 <events>
 <EVT_TIMER_SELBSTHALT index="0" access="MIXED"/>
 <EVT_TIMER_SWITCHWAIT index="1" access="MIXED"/>
 </events>
 <connectors>
 </connectors>
 <methods>
 </methods>
 </machine>
 </machines>

 Automaton::ATML::end
 */

