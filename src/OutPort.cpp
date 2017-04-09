#include "OutPort.h"


OutPort::OutPort(std::string n, std::string t) : Port(n,t){}

void OutPort::print(std::ostream& os) const {
  os << "<dataOut name='" << this->name << ", type='" << this->type <<"'/>\n";
}
