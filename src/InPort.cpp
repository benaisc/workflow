#include "InPort.h"


InPort::InPort(std::string n, std::string t) : Port(n,t), set(""){}

InPort::InPort(std::string n, std::string t, std::string s) : Port(n,t), set(s){}

bool InPort::isSetted() const{
  return this->set != "";
}

void InPort::print(std::ostream& os) const {
  os << "<dataIn name='" << this->name << ", type='" << this->type <<"'";
  if(isSetted())
    os << ", set='" << this->set << "'";
  os << "/>\n";
}
