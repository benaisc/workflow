#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__


class Instruction
{
private:
    CreateInstance createInstance;
	ExecTask execTask;
	ConfigPort configPort;
	Sequence sequence;

public:
    Instruction();
};

#endif
