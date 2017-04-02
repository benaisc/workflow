#include "STCMAssembly.h"


STCMAssembly::STCMAssembly(){}

STCMAssembly* STCMAssembly::parse(FILE* stcmXmlPath){
	//TODO
}

Declare* STCMAssembly::getDeclarations(){
	//TODO
}

Instruction* STCMAssembly::getInstructions(){
	//TODO
}

std::ostream &operator<<(std::ostream& os, const STCMAssembly &STCM)
{
  STCM.print(os);
  return os;
}

void STCMAssembly::print(std::ostream &os){
	declarations.print(&os);
	instructions.print(&os);
}
