/**
 * Project TO52
 */


#ifndef _CONF_H
#define _CONF_H

#define DEFAULT_CONF_FILE "conf.json"

#include <iostream>
#include <fstream>
#include <string>
#include "lib/json.hpp"

using namespace std;
using json = nlohmann::json;

#define CLOCK_MQTT_ID "Clock"
#define CLOCK_MQTT_SERVER "192.168.0.31"
#define CLOCK_MQTT_PORT 1883
#define CLOCK_MQTT_TOPIC "/clock"

class Conf{
public:

	string getMQTTId();
	string getMQTTServer();
	int getMQTTPort();
	string getMQTTTopic();

	static Conf& getInstance();

private:

	Conf();

	static Conf singleton;

	json conf;

};

#endif
