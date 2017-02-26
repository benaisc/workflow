#ifndef __PORT_H__
#define __PORT_H__

#include <string>


class Port
{
protected:
    string name;
    string type;

public:
	explicit Port(string name, string type);
};

#endif // PORT_H
