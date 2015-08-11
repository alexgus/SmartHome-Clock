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

    this->mqtt = new MQTTConnection(CLOCK_MQTT_ID,CLOCK_MQTT_SERVER,CLOCK_MQTT_PORT);
    this->mqtt->connect();
    this->mqtt->subscribe(CLOCK_MQTT_TOPIC,*this);
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
        ; // TODO

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

}

void Clock::delayedRing() {
	this->delay.play();
	this->ring();
}

void Clock::setISR() {

}

