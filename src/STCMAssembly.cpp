#include "STCMAssembly.h"


STCMAssembly::STCMAssembly(){
	this.declarations = new Declare();
	this.instructions = new Instruction();
}

STCMAssembly* STCMAssembly::parse(FILE* stcmXmlPath){
	//TODO
}

Declare STCMAssembly::getDeclare(){
	//TODO
}

Instruction STCMAssembly::getInstruction(){
	//TODO
}
