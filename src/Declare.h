#ifndef __DECLARE_H__
#define __DECLARE_H__

#include <unordered_map>
#include "Component.h"
#include "Instance.h"
#include "ConfigPort.h"

class Declare
{
private:
		std::unordered_map<std::string, Component> components;
		std::unordered_map<std::string, Instance> instances;
		ConfigPort configPort;

public:
    Declare();

		void addComponent(const char* name, Component &c);
		void addInstance(const char* name, Instance &i);
		void setPorts(ConfigPort &cfg);

		//Component* getComponent(std::string name);
		//Instance* getInstance(std::string name);
		ConfigPort* getConfigPort();

		//avec get() y'à pas de boundary check dc à voir
		Component* searchComponent(std::string name);
		Instance* searchInstance(std::string name);

		void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream& os, const Declare &d);
#endif
