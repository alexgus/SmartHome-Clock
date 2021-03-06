/**
 * Project TO52
 */


#include "Clock.h"

char Cmd[][16] = { "RING", "SNOOZE", "ABORT", "DISMISS", "CONF_DELAY" };

/**
 * Clock implementation
 */
Clock *c;

/**
 * Launch event in thread for being processing out of ISR
 */
thread *tevent;

void funThreadStop(){
	c->stopRinging();
}

void funThreadSnooze(){
	c->delayedRing();
}

/**
 * handle pushed button
 */
void ISRStop(){
	tevent = new thread(funThreadStop);
}

void ISRSnooze(){
	tevent = new thread(funThreadSnooze);
}

Clock::Clock() {
	c = this;
	state = IDLE;

	this->setISR();
	this->_ring = Ring();

	this->secSnooze = SNOOZE_TIME;

	this->mqtt = new MQTTConnection(Conf::getInstance().getMQTTId(),
			Conf::getInstance().getMQTTServer(),
			Conf::getInstance().getMQTTPort());
	this->mqtt->connect();
	this->mqtt->subscribe(Conf::getInstance().getMQTTTopic(),*this);

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

	if(payload.find(string(Cmd[1])) == 0) // SNOOZE
		this->delayedRing();

	if(payload.find(string(Cmd[2])) == 0) // ABORT
		this->stopRinging();

	if(payload.find(string(Cmd[3])) == 0) // DISMISS
		this->stopRinging();

	if(payload.find(string(Cmd[4])) == 0){ // CONF_DELAY
		string s = payload.substr(string(Cmd[4]).length() + 1);
		this->secSnooze = stoi(s, NULL,10);
	}
}

/**
 * @param state
 */
void Clock::publishState(State state) {
	this->mqtt->publish(Conf::getInstance().getMQTTTopicState(), StateStrings[state]);
}

void Clock::ring() {
	this->mstate.lock();
	if(this->state != RINGING){
		this->state = RINGING;
		this->mstate.unlock();

		this->_ring.play();

		this->publishState(RINGING);
	}
	this->mstate.unlock();
}

void Clock::stopRinging() {
	this->mstate.lock();
	if(this->state == RINGING){
		this->state = IDLE;
		this->mstate.unlock();

		this->_ring.stop();

		this->publishState(IDLE);
	}
	this->mstate.unlock();
}

void Clock::delayedRing() {
	this->mstate.lock();
	if(this->state == RINGING){
		this->state = DELAYED;
		this->mstate.unlock();

		this->_ring.stop();

		this->publishState(DELAYED);
		sleep(this->secSnooze);

		this->ring();
	}
	this->mstate.unlock();
}

void Clock::setISR() {
	wiringPiISR(PIN_DISMISS_BUTTON, INT_EDGE_BOTH, ISRStop);
	wiringPiISR(PIN_SNOOZE_BUTTON, INT_EDGE_BOTH, ISRSnooze);
}

