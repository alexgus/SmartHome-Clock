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

class Conf{
public:
	Conf();

	string getMQTTServer();

private:

	json conf;

};

#endif
