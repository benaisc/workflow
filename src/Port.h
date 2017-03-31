#ifndef __PORT_H__
#define __PORT_H__

#include <string>


virtual class Port
{
protected:
    string name;
    string type;

public:
	explicit Port(string name, string type);

  void print();
};

#endif // PORT_H
