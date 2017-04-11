/*! \file STCMAssembly.h
    \brief A Class used to contain STCM-XML's as object.

    Simply built by our Parser to reduce dependencys.
*/

#ifndef __STCMASSEMBLY_H__
#define __STCMASSEMBLY_H__

#include "Declare.h"

//#include "Instruction.h"

/*! \class STCMAssembly
    \brief Template class for base STCMAssembly objects.

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

		/*! \fn getDeclarations()
			\brief Simple getter of declarations object.
		*/
		Declare* getDeclarations();
		//Instruction* getInstructions();

		/*! \fn print()
			\brief Simple printer to illustrate processes & possibilities
		*/
		void print(std::ostream& os) const;
};
/*! \fn operator<<()
	\brief Simple override of << operator to print out easily the objects
*/
std::ostream &operator<<(std::ostream& os, const STCMAssembly &STCM);

#endif
