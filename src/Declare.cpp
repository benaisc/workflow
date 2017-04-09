#include "Declare.h"

Declare::Declare(){}

/*
Component* Declare::getComponent(std::string name){
	return this.components[name];
}

Instance* Declare::getInstance(std::string name){
	return this.instances[name];
}

ConfigPort* Declare::getConfigPort(){
	return this.configPort;
}
*/
void Declare::addComponent(const char* name, Component &c){
	this->components[name] = c;
}
/*
void Declare::addInstance(std::string name, Instance i){
	this.instances[name] = i;
}
*/

Component* Declare::searchComponent(std::string name){
	auto search = this->components.find(name);
	if(search != this->components.end()) {
			//std::cout << "Found " << search->first << " " << search->second << '\n';
			return &search->second;
	}
	else {
			return NULL;
	}
}
/*
Instance* Declare::searchInstance(std::string name){
	auto search = this.instances.find(name);
	if(search != this.instances.end()) {
			//std::cout << "Found " << search->first << " " << search->second << '\n';
			return search->second;
	}
	else {
			return NULL;
	}
}
*/

void Declare::print(std::ostream& os) const {
	os << "<Declare>\n";

	for (auto &c : this->components)
		std::get<1>(c).print(os);

	//foreach(Instance i : this.instances){i.print();}
	//configPort.print(&os);
	os << "</Declare>\n";
}

std::ostream &operator<<(std::ostream& os, const Declare &d)
{
  d.print(os);
  return os;
}
