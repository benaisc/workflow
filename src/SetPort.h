#ifndef __SETPORT_H__
#define __SETPORT_H__

//#include "InPort.h"
//#include "OutPort.h"

#include <iostream>
#include <string>

class SetPort
{
private:
	std::string in;
	std::string out;

public:
  SetPort(std::string in, std::string out);

	void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream& os, const SetPort &port);

#endif // SETPORT_H
