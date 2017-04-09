#ifndef __OUTPORT_H__
#define __OUTPORT_H__

#include "Port.h"


class OutPort : public Port
{
public:
    OutPort(std::string n, std::string t);

    //@Override
    void print(std::ostream& os) const;
};

#endif // OUTPORT_H
