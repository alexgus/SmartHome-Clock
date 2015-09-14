/**
 * Project TO52
 */


#ifndef _CLOCK_H
#define _CLOCK_H

#include <string>
#include <iostream>

#include "Conf.h"
#include "State.h"
#include "Delay.h"
#include "Ring.h"
#include "MQTTCallback.h"
#include "MQTTConnection.h"

using namespace std;

class Clock: public MQTTCallback {
public: 
    static int onOffBUTTON;
    static int snoozeBUTTON;
    static int dismissBUTTON;
    static string subscribedTopic;
    static string publishTopic;
    
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
    State state;
    Delay delay;
    Ring _ring;
    MQTTConnection *mqtt;

    void setISR();
};

#endif //_CLOCK_H
