/**
 * Project TO52
 */


#ifndef _CLOCK_H
#define _CLOCK_H

#include <string>
#include <iostream>

#include "State.h"
#include "Delay.h"
#include "Ring.h"
#include "MQTTCallback.h"
#include "MQTTConnection.h"

#define CLOCK_MQTT_ID "Clock"
#define CLOCK_MQTT_SERVER "192.168.0.31"
#define CLOCK_MQTT_PORT 1883
#define CLOCK_MQTT_TOPIC "/clock"

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
     * handle pushed button
     */
    void ISR();
    
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
