/*! \file STCMAssembly.h
    \brief A Parser used to query STCM-XML's.
    
    Simply built on libxml2 to reduce dependencys.
*/

#ifndef __STCMASSEMBLY_H__
#define __STCMASSEMBLY_H__

#include <libxml2>
#include <iostream>

/*! \class STCMAssembly
    \brief Template for base STCMAssembly class.

    It contains the prerequisite functions used to
	fill an STCMAssembly object from an STCM-XML file.
*/
class STCMAssembly{
	private:
		Declare declarations;
		Instruction instructions;

	public:
		/*! \fn STCMAssembly()
			\brief Simple constructor of STCMAssembly objects.
		*/
		STCMAssembly();

		/*! \fn parse(FILE* stcmXml)
			\brief Constructor from a file
			\param stcmXml A pointer to the STCMAssembly XML
			\return A filled STCMAssembly object or NULL.
		*/
		STCMAssembly* parse(FILE* stcmXmlPath);
		
		Declare getDeclare();
		Instruction getInstruction();		
};

#endif
