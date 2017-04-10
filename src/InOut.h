#ifndef __INOUT_H__
#define __INOUT_H__

#include "SetPort.h"
#include <list>

class InOut
{
private:
    std::list<SetPort> setports;
    //UnSetPort* unsetPorts

public:
    InOut();

    void addPort(SetPort &link);

    void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream& os, const InOut &ports);

#endif
