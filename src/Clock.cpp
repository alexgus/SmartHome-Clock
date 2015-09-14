/**
 * Project TO52
 */


#include "Clock.h"

char Cmd[][16] = { "RING", "SNOOZE", "ABORT", "DISMISS", "CONF_DELAY" };

/**
 * Clock implementation
 */


Clock::Clock() {
	this->setISR();
	this->_ring = Ring();
	this->delay = Delay();

    this->mqtt = new MQTTConnection(Conf::getInstance().getMQTTId(),
    		Conf::getInstance().getMQTTServer(),
    		Conf::getInstance().getMQTTPort());
    this->mqtt->connect();
    this->mqtt->subscribe(Conf::getInstance().getMQTTTopic(),*this);
}

/**
 * handle pushed button
 */
void Clock::ISR() {

}

/**
 * Callback when payload of subscribed topic is received
 * @param topic
 * @param payload
 */
void Clock::callback(string topic, string payload) {
    cout << "Clock : " << topic << " " << payload << endl;

    
    if(payload.find(string(Cmd[0])) == 0) // RING
        this->ring();

    if(payload.find(string(Cmd[2])) == 0) // ABORT
        this->stopRinging()

    if(payload.find(string(Cmd[4])) == 0){ // CONF_DELAY
        string s = payload.substr(string(Cmd[4]).length() + 1);
        int sec = stoi(s, NULL,10);
    	this->delay = Delay(sec);
    }
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
	this->_ring.stop();
}

void Clock::delayedRing() {
	this->delay.play();
	this->ring();
}

void Clock::setISR() {

}

