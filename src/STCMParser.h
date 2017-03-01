/*! \file STCMParser.h
    \brief A Parser used to query STCM-XML's.
    
    Simply built on libxml2 to reduce dependencys.
*/

#ifndef __STCMPARSER_H__
#define __STCMPARSER_H__

#include "STCMAssembly.h"
#include <libxml2>

/*! \class STCMParser
    \brief Template for base STCMParser class.

    It contains the prerequisite functions used to
	fill an STCMAssembly object from an STCM-XML file.
*/
class STCMParser{
	public:
		/*! \fn STCMParser()
			\brief Simple constructor of STCMParser objects.
		*/
		STCMParser();

		/*! \fn parse(FILE* stcmXml)
			\brief Constructor from a file
			\param stcmXml A pointer to the STCMAssembly XML
			\return A filled STCMAssembly object or NULL.
		*/
		STCMAssembly* parse(FILE* stcmXml);
};


#endif
