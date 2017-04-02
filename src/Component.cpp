#include "Component.h"


Component::Component(string nameAttr) : name(nameAttr){}

void Component::addOutPort(OutPort outp){
  this.outports.push_front(outp);
}

void Component::addInPort(InPort inp){
  this.inports.push_front(inp);
}

std::list<OutPort>* Component::getOutPorts() const{
  return &this.outports;
}

std::list<InPort>* Component::getInPorts() const{
  return &this.inports;
}

void Component::print(){
  std::cout << "Composant '" << this.name << "' : \n";
  this.inports.print();
  this.outports.print();
}
