/**
 * Project TO52
 */


#include "Ring.h"

/**
 * Ring implementation
 */

void Ring::Ring(){
	wiringPiSetup();
	pinMode(0, OUTPUT);
}

void Ring::play() {
	cout << "Ringing" << endl;
	for (;;)
	{
		digitalWrite (0, HIGH) ; delay (5) ;
		digitalWrite (0,  LOW) ; delay (5) ;
	}
}
