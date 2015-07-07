/**
 * Project TO52
 */


#ifndef _CLOCK_H
#define _CLOCK_H

#include <string>

#include "State.h"
#include "Delay.h"
#include "Ring.h"

using namespace std;

class Clock {
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
     * @param payload
     */
    void handlePayload(string payload);
    
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

    void setISR();
};

#endif //_CLOCK_H
