#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include <Component.h>

using namespace std;


class Instance{
	private:
		string name;
		Component componentRef;
		string parameters;

	public:
		Instance(string name, Component c);
		Instance(string name, Component c, string param);

		bool setComponent(Component c);
		Component getComponent() const;
};


#endif

/**
Question:
Est-ce que on ajoute dans nos classes les informations qui seront déterminées par notre ordonnanceur (ex : la data contenant la valeur du port dans la classe Port)
OU
Est-ce que notre ordonnanceur infèrera ces informations dans les classes qui utiliseront les autres classes ?

EX : 
1) on met value dans port
2) on hashmap les objets en leur donnant une value


Component utilisé pour déclarer les trucs

Instance utilisé en : 
1) RECOPIE des attributs de Component (== déclaration) ++ instanciation + affectation
2) affectation seulement depuis Instance des attributs de Component (impossible ?)


DECLARATION SIMPLE : 
Donc l'UML ne fait que déclarer les structures permettant ENSUITE de créer ces objets via un framework

ex : Port(nomport, typeport)

le framework prend ça, crée un objet nomport de type typeport et il "sait" quoi faire avec ce port


CONCLUSION
NOTRE UML NE FAIT QUE DEFINIR EXPLICITEMENT LE SCHEMA DES OBJETS DÉCLARÉS DANS L'XML
Ces objets n'effectuent aucune action, n'ont d'autres traitements que le nommage, le référencement et typage.

C'est la structure qui nous permettra d'éxécuter le workflow
Il se charge de toutes les informations du XML dans le code

EN GROS, ça nous permet surtout de pas avoir à mélanger du XQuery dans l'execution
On peut voir ça comme la 1ere couche permettant de Parser

XML => Objet
Objet => framework
framework => bytecode
**/
