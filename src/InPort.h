#ifndef __INPORT_H__
#define __INPORT_H__

#include "Port.h"


class InPort : public Port
{
private:
    string set;

public:
    InPort(string n, string t);
    InPort(string n, string t, string s);

    bool isSetted() const;
};

#endif
