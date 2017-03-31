/*! \file Balise.h
    \brief A Documented template file.

    +Xtra Details.
*/

#ifndef __Balise_H__
#define __Balise_H__

#include "hashmap.h"

/*! \class Balise
    \brief A Balise class.

    A detailed description.
*/
class Balise{
	private:
		/*! \var name
			\brief name of balise
		*/
		char* name;
		/*! \var attributs
			\brief attributes of the balise (i.e: id="1234")
		*/
		Hashmap<String, String>* attributs;
		/*! \var name
			\brief name of balise
		*/
		Balise* fils;

	public:
		/*! \fn void getName()
			\brief return the name of the balise as a string
			\return Balise.name
		*/
		char* getName();

		int addChild(Balise);

};

#endif
