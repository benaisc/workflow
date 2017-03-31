#ifndef __DECLARE_H__
#define __DECLARE_H__

#include <unordered_map>
#include "Component.h"
#include "Instance.h"
#include "ConfigPort.h"

class Declare
{
private:
		std::tr1::unordered_map<std::string, Component> components;
		std::tr1::unordered_map<std::string, Instance> instances;
		ConfigPort configPorts;

public:
    Declare();

		Component* getComponent(std::string name);
		Instance* getInstance(std::string name);
		ConfigPort* getConfigPort();

		int addComponent(std::string name, Component c);
		int addInstance(std::string name, Instance i);

		//avec get() y'à pas de boundary check dc à voir
		Component* searchComponent(std::string name);
		Instance* searchInstance(std::string name);

		void print();
};

#endif
