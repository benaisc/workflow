#ifndef __DECLARE_H__
#define __DECLARE_H__

#include <tr1/unordered_map>


class Declare
{
private:    
	std::tr1::unordered_map<std::string, Component> components;
	std::tr1::unordered_map<std::string, Instance> instances;
	ConfigPort configPorts;

public:
    Declare();

	Component getComponent(String name);
	Instance getInstance(String name);
	ConfigPort getConfigPort();
};

#endif
