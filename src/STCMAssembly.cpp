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

void STCMAssembly::print(){
	declarations.print();
	instructions.print();
}
