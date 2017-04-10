#include "ConfigPort.h"


ConfigPort::ConfigPort(){}

void ConfigPort::setInOut(InOut &localPorts){
  inout = localPorts;
}

void ConfigPort::print(std::ostream& os) const{
	os << "<ConfigPort>\n";

  this->inout.print(os);

  os << "</ConfigPort>\n";
}

std::ostream &operator<<(std::ostream& os, const ConfigPort &cfg){
  cfg.print(os);
  return os;
}
