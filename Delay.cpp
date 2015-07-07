/**
 * Project TO52
 */


#include "Delay.h"

/**
 * Delay implementation
 */


Delay::Delay() {
	Delay(this->defaultDelay);
}

/**
 * @param s
 */
Delay::Delay(int s) {
	this->sDelay = s;
}

void Delay::play() {
	sleep(this->sDelay);
}
