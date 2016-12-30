#include "Automaton.h"
#include "J_down.h"

// Basic Arduino sketch - instantiates the state machine and nothing else

J_down J_downI;

void setup() {

	// Serial.begin( 9600 );
	// J_down.trace( Serial );
	  Serial.begin( 9600 );
	  Serial.println( "Started" );
	  J_downI.begin(4, 5).automatic(20, 50, 60);
	;

}

void loop() {
	automaton.run();
}
