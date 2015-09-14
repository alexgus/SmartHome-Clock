/**
 * Project TO52
 */


#include "Ring.h"

/**
 * Ring implementation
 */

Ring::Ring(){
	wiringPiSetup();
	pinMode(0, OUTPUT);
}

void Ring::play() {
	cout << "Ringing" << endl;
	for (;;)
	{
		digitalWrite (0, HIGH);
		delayMicroseconds (500);
		digitalWrite (0,  LOW);
		delayMicroseconds (500);
	}
}
