#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__


class Sequence
{
private:
    Port port;
	Attribute* attributes;
	Declare declare;
	Instruction* instructions;

public:
    Sequence();
};

#endif
