/*! \file STCMAssembly.h
    \brief A Parser used to query STCM-XML's.

    Simply built on libxml2 to reduce dependencys.
*/

#ifndef __STCMASSEMBLY_H__
#define __STCMASSEMBLY_H__

#include "Declare.h"

//#include "Instruction.h"

/*! \class STCMAssembly
    \brief Template for base STCMAssembly class.

    It contains the prerequisite functions used to
		fill and manipulate STCMAssembly object parsed
		from an STCM-XML file.
*/
class STCMAssembly{
	private:
		Declare declarations;
		//Instruction instructions;

	public:
		/*! \fn STCMAssembly()
			\brief Simple constructor of STCMAssembly objects.
		*/
		STCMAssembly();

		Declare* getDeclarations();
		//Instruction* getInstructions();

		void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream& os, const STCMAssembly &STCM);

#endif
