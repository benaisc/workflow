#ifndef __CREATEINSTANCE_H__
#define __CREATEINSTANCE_H__


class CreateInstance
{
private:
    string name;
	string componentRef;
	string parameters

public:
    CreateInstance(string name, string compoRef, params);
};

#endif
