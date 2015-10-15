#include "Conf.h"

Conf Conf::singleton = Conf();

Conf::Conf(){
	string line, file;
	ifstream confFile (DEFAULT_CONF_FILE);
	if (confFile.is_open()) {
		while (getline (confFile,line))
			file.append(line + '\n');
		confFile.close();
	}

	try{
		this->conf = json::parse(file);
	}catch(invalid_argument e){
		cout << "Configuration file is missing or some attributes missing" << endl;
		cout << e.what() << endl;
	}
}

Conf& Conf::getInstance(){
	return singleton;
}

string Conf::getMQTTId(){
	return this->conf["MQTT"]["id"];
}

string Conf::getMQTTServer(){
	return this->conf["MQTT"]["server"];
}

int Conf::getMQTTPort(){
	return this->conf["MQTT"]["port"];
}

string Conf::getMQTTTopic(){
	return this->conf["MQTT"]["topic"];
}

string Conf::getMQTTTopicState(){
	return this->conf["MQTT"]["topicState"];
}
