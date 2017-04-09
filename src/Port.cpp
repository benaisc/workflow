#include "Port.h"


Port::Port(std::string n, std::string t) : name(n), type(t) {}

std::ostream &operator<<(std::ostream& os, const Port &iop){
  os << "<Port>\n";
  iop.print(os);
  os << "</Port>\n";
  return os;
}
