#ifndef __INPORT_H__
#define __INPORT_H__

#include "Port.h"

class InPort : public Port
{
private:
    std::string set;

public:
    InPort(std::string n, std::string t);
    InPort(std::string n, std::string t, std::string s);

    bool isSetted() const;

    //@Override
    void print(std::ostream& os) const;
};

#endif
