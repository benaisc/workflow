#include "Port.h"


Port::Port(string n, string t) : name(n), type(t) {}

void Port::print(){
  std::cout << name << " : " << type << std::endl;
}
