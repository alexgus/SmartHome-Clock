/**
 * Project TO52
 */


#include "Clock.h"

/**
 * Clock implementation
 */


Clock::Clock() {
	this->setISR();
	this->_ring = Ring();
	this->delay = Delay();
}

/**
 * handle pushed button
 */
void Clock::ISR() {

}

/**
 * Callback when payload of subscribed topic is received
 * @param payload
 */
void Clock::handlePayload(string payload) {

}

/**
 * @param state
 */
void Clock::publishState(State state) {

}

void Clock::ring() {
	this->_ring.play();
}

void Clock::stopRinging() {

}

void Clock::delayedRing() {
	this->delay.play();
	this->ring();
}

void Clock::setISR() {

}
