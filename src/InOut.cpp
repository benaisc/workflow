#include "InOut.h"


InOut::InOut(){}


void InOut::addPort(SetPort &link){
  this->setports.push_front(link);
}

void InOut::print(std::ostream& os) const{
  os << "<InOut>\n";

  for (auto &p : this->setports)
    p.print(os);

  os << "</InOut>\n";
}

std::ostream &operator<<(std::ostream& os, const InOut &ports){
  ports.print(os);
  return os;
}
