#include "Declare.h"

Declare::Declare(){}


Component Declare::getComponent(String name){
	return this.components[name];
}

Instance Declare::getInstance(String name){
	return this.instances[name];
}

ConfigPort Declare::getConfigPort(){
	return this.configPort;
}
