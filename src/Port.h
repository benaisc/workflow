#ifndef __PORT_H__
#define __PORT_H__

#include <iostream>

class Port
{
protected:
    std::string name;
    std::string type;

public:
	explicit Port(std::string name, std::string type);

  virtual void print(std::ostream& os) const {}
};

std::ostream &operator<<(std::ostream& os, const Port &iop);
#endif // PORT_H
