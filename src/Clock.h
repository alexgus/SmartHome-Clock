/**
 * Project TO52
 */


#ifndef _CLOCK_H
#define _CLOCK_H

#include <string>
#include <iostream>
#include <wiringPi.h>
#include <thread>
#include <mutex>
#include <unistd.h>

#include "Conf.h"
#include "State.h"
#include "Ring.h"
#include "MQTTCallback.h"
#include "MQTTConnection.h"

#define DISMISS_TIME 60
#define SNOOZE_TIME  3

using namespace std;

class Clock: public MQTTCallback {
public: 
    static int onOffBUTTON;
    static int snoozeBUTTON;
    static int dismissBUTTON;
    
    Clock();
    
    /**
     * Callback when payload of subscribed topic is received
     * @param topic
     * @param payload
     */
    virtual void callback(string topic, string payload);
    
    /**
     * @param state
     */
    void publishState(State state);
    
    void ring();
    
    void stopRinging();
    
    void delayedRing();
private: 
    int id;
    int secSnooze;
    Ring _ring;
    MQTTConnection *mqtt;
    mutex mstate;
    State state;

    void setISR();
};

#endif //_CLOCK_H
