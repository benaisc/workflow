#include "InPort.h"


Inport::Inport(string n, string t) : Port(n,t), set(""){}

Inport::Inport(string n, string t, string s) : Port(n,t), set(s){}

bool Inport::isSetted() const{
  return set != "";
}
