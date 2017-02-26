#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__


class Attribute
{
private:
    string set;

public:
    Attribute(string n, string t);
    Attribute(string n, string t, string s);

    bool isSetted() const;
};

#endif
