#include "STCMAssembly.h"


STCMAssembly::STCMAssembly() : declarations(){}

STCMAssembly* STCMAssembly::parse(std::string stcmXmlPath){
	std::cout << "parse()..\n";
	//TODO: voir domParser_exemple.cpp
	/*
	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	doc = xmlReadFile(argv[1], NULL, 0);

	if (doc == NULL) {
		printf("error: could not parse file at '%s'\n", stcmXmlPath);
		return(NULL);
	}

	root_element = xmlDocGetRootElement(doc);

	//STCMAssembly assembly;
	//parse_stcm(root_element, this);
	parse_stcm(root_element);

	//assembly.wiggle();

	xmlFreeDoc(doc);
	xmlCleanupParser();
	*/
	return(this);
}
/*
Declare* STCMAssembly::getDeclarations(){
	return this.declarations;
}

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
