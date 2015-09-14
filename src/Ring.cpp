/**
 * Project TO52
 */


#include "Ring.h"

/**
 * Ring implementation
 */

mutex mtx;
bool running;

void ringPlay(){
	mtx.lock();
	while(running == true)
	{
		mtx.unlock();

		digitalWrite (0, HIGH);
		delayMicroseconds (500);
		digitalWrite (0,  LOW);
		delayMicroseconds (500);
	}
}


Ring::Ring(){
	wiringPiSetup();
	pinMode(0, OUTPUT);
	running = false;
}

void Ring::play() {
	cout << "Ringing" << endl;

	mtx.lock();

	if(running != true){
		running = true;

		mtx.unlock();

		this->t = new thread(ringPlay);
	}
}

void Ring::stop(){
	mtx.lock();
	running = false;
	mtx.unlock();
}

