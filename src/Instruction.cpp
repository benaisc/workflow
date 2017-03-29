#include "Instruction.h"

Instruction::Instruction() : createInstance(), execTask(), configPort(), sequence() {}


Sequence Instruction::getSequence(){
	return this.sequence;
}

