#ifndef SETPORT_H
#define SETPORT_H

#include "InPort.h"
#include "OutPort.h"


class SetPort
{
private:
	string in;
	string out;

public:
    SetPort(string in, string out);
};

#endif // SETPORT_H
