#ifndef PORT_H
#define PORT_H

#include string.h

using namespace std;

class Port
{
private:
    string name;
    string type;

public:
    virtual Port(string n, string t);
};

#endif // PORT_H
