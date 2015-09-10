#include "Conf.h"

Conf::Conf(){
	string line, file;
	ifstream confFile (DEFAULT_CONF_FILE);
	if (confFile.is_open()) {
		while (getline (confFile,line))
			file.append(line + '\n');
		confFile.close();
	}

	this->conf = json::parse(file);
}

string Conf::getMQTTServer(){
	return "";
}
