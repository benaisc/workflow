#ifndef __ORDONNANCEUR_H__
#define __ORDONNANCEUR_H__

#include "STCMAssembly.h"

class Ordonnanceur{
	private:
		static Ordonnanceur* SINGLETON = NULL;
		//un vecteur de composants instanciables
		//une structure/objet pour le data-flow de la <ConfigPort>
		//une structure/objet permettant de représenter les instructions
		//une structure/objet pour les composants instanciés?
		//?

		Ordonnanceur(STCMAssembly &assembly);

	public:
		Ordonnanceur* getOrdonnanceur(const char * pathToXml);

		/*
		bool inspectDeclare();
		* vérifie la véracité des informations contenues dans <Declare> :
		* <Component> : bool inspectComponents();
		** name: unicité
		* <dataIn/Out>
		** name: unicité dans le composant
		** type: adaptable

		* <Instance> : bool inspectInstances();
		** name: unicité
		** componentRef: existence
		** path: existence
		** signature: adaptable

		* <setPort> : bool inspectConfigPort();
		** in: existence
		** out: existence
		** On valide donc que le in est un <dataIn> du componentRef de l'<Instance>
		** (pareil pour le out)
		*** Si j'ai bien compris, les <setPort> de la <ConfigPort>
		*** et son <InOut> associé servent à indiquer la volonté de transmettre
		*** des données entre les ports de composants en fonction des instructions,
		*** c'est à dire que quelque soit les composants instanciés, il faudra
		*** orchestrer cette transmission, donc les instructions servent à
		*** conditionner l'instanciation des composants, et on applique une stratégie
		*** liée à l'interprétation des instructions :
		*** 1) l'instruction est conditionnée par les transmissions de la <ConfigPort>
		**** Une fois un composant instancié par <execTask>, l'Ordonnanceur se basera
		**** sur la <ConfigPort> pour déterminer les actions à prendre avant de pouvoir
		**** mettre fin au composant et passer à l'instruction suivante.
		**** <Sequence>:
		**** Impossible de commencer l'exécution par un composant avec des dataIn...
		*** 2) l'instruction n'est pas conditionnée par la transmission de la ConfigPort
		**** <Sequence>:
		**** impossible?
		*** 3) pas d'instructions, l'ordonnanceur ne se base que sur la <ConfigPort>
		**** pour orchestrer l'instanciation et le transfert des données entre les composants

		bool inspectInstruction();
		* vérifie la validité des informations contenues dans le bloc d'instructions :
		* ?

    bool inspectAssembly();
		* Suppose l'assembly construit sur les bases d'un XML validé par Schéma XSD
		* Valide l'assemblage sur la base des fonctions définies ci-dessus;
		*/

		
		/*
			il nous faudrait implémenter un système de headers permettant à l'ordonnanceur 
			de générer du code par le lien des méthodes déclarées dans l'XML et nous offrir
			la possibilitée d'appeler les méthodes distantes des instances de composants
		*/










};
#endif
