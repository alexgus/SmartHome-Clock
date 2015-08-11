/**
 * Project TO52
 */


#ifndef _MQTT_H
#define _MQTT_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <MQTTClient.h>

#include "MQTTCallback.h"

using namespace std;

class MQTT {
public: 
    /**
     * @param topic
     * @param payload
     */
    virtual void publish(string topic, string payload) = 0;
    
    /**
     * @param topic
     * @param callback
     */
    virtual void subscribe(string topic, MQTTCallback &cb) = 0;
};

#endif //_MQTT_H
