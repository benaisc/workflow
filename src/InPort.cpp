#include "InPort.h"

Inport::Inport(string n, string t)
{
    Port::Port(n, t);
}

Inport::Inport(string n, string t, string s)
{
    Port::Port(n, t);
    this.set = s;
}

