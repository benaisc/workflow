#include "Component.h"


Component::Component() : name("Unknown"){}
Component::Component(const char* nameAttr) : name(nameAttr){}
Component::Component(const Component &c) : name(c.name){}

void Component::addOutPort(OutPort outp){
  this->outports.push_front(outp);
}

void Component::addInPort(InPort inp){
  this->inports.push_front(inp);
}
/*
std::list<OutPort>* Component::getOutPorts() const{
  return &this.outports;
}

std::list<InPort>* Component::getInPorts() const{
  return &this.inports;
}
*/
void Component::print(std::ostream& os) const {
  os << "<Component name='" << this->name << "'>\n";
  for (auto &p : this->inports)
    p.print(os);
  for (auto &p : this->outports)
    p.print(os);
  os << "</Component>\n";
}

std::ostream &operator<<(std::ostream& os, const Component &c)
{
  c.print(os);
  return os;
}
