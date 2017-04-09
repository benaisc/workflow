#include "STCMAssembly.h"


STCMAssembly::STCMAssembly() : declarations(){}


Declare* STCMAssembly::getDeclarations(){
	return &this->declarations;
}
/*
Instruction* STCMAssembly::getInstructions(){
	//TODO
}
*/

void STCMAssembly::print(std::ostream &os) const {
	os << "<STCMAssembly>\n";
	declarations.print(os);
	//instructions.print(&os);
	os << "</STCMAssembly>\n";
}

std::ostream &operator<<(std::ostream& os, const STCMAssembly &STCM)
{
  STCM.print(os);
  return os;
}
