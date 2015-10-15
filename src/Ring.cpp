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
	//mtx.lock();
	while(running)
	{
		//mtx.unlock();

		digitalWrite (0, HIGH);
		delayMicroseconds (500);
		digitalWrite (0,  LOW);
		delayMicroseconds (500);
		//mtx.lock();
	}
	//mtx.unlock();
}


Ring::Ring(){
	pinMode(0, OUTPUT);
	running = false;
}

void Ring::play() {
	mtx.lock();

	if(!running){
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

