#ifndef INPORT_H
#define INPORT_H

#include "Port.h"
#include string.h

using namespace std;

class InPort::Port
{
private:
    string set;

public:
    InPort(string n, string t);
    InPort(string n, string t, string s);
};

#endif // PORTIN_H
