#ifndef __CONFIGPORT_H__
#define __CONFIGPORT_H__

#include "InOut.h"

class ConfigPort
{
private:
    InOut inout;

public:
    ConfigPort();
    void setInOut(InOut &localPorts);

    void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream& os, const ConfigPort &cfg);

#endif
