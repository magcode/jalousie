#include "Automaton.h"
#include "J_down.h"

// Basic Arduino sketch - instantiates the state machine and nothing else

J_down J_down1;
J_down J_down2;

void setup() {

	  Serial.begin( 9600 );
	  Serial.println( "Started" );

	  Atm_digital buttonDown1;
	  Atm_digital buttonUp1;
	  Atm_digital buttonStop2;

	  Atm_digital buttonDown2;
	  Atm_digital buttonUp2;
	  //simulation 5ms press -> start
	  //buttonDown1.begin( 2, 5 ).onChange( J_down1, J_down1.EVT_ON );

	  buttonStop2.begin( 1, 5 ).onChange( J_down2, J_down2.EVT_STOP );
	  buttonDown2.begin( 3, 5 ).onChange( J_down2, J_down2.EVT_ON );
	  buttonDown1.begin( 2, 5 ).onChange( J_down2.configure(0, 0) );


	  //buttonStop2.begin( 1, 5 ).onChange( J_down2, J_down2.EVT_ON );

	  J_down1.begin(4, 5).setchannel('1').configure(600, 300);
	  J_down2.begin(6, 7).setchannel('2').configure(600, 300);


}

void loop() {
	automaton.run();
}
