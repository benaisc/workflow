#include "SetPort.h"

SetPort::SetPort(std::string in, std::string out) : in(in), out(out){}

void SetPort::print(std::ostream& os) const{
  os << "<SetPort in='" << this->in << "', out='" << this->out << "'/>\n";
}

std::ostream &operator<<(std::ostream& os, const SetPort &port){
  port.print(os);
  return os;
}
