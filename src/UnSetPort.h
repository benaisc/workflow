#ifndef __UNSETPORT_H__
#define __UNSETPORT_H__

#include "InPort.h"
#include "OutPort.h"


class UnSetPort
{
private:
	string in;
	string out;

public:
    SetPort(string in);
    SetPort(string in, string out);
};

#endif
