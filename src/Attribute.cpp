#include "Attribute.h"


Attribute::Attribute(string n, string t) : name(n), type(t), set(""){}

Attribute::Attribute(string n, string t, string s) : Port(n,t), set(s){}

bool Attribute::isSetted() const{
  return set != "";
}
