#include "Ordonnanceur.h"


Ordonnanceur::Ordonnanceur(const STCMAssembly &assembly){
  //TODO: construit les structures nécéssaires à l'orchestration
  //bool inspectAssembly(); ?? tant qu'à le valider autant le digérer en simultané
}

Ordonnanceur* Ordonnanceur::getOrdonnanceur(const char * pathToXml){
  if (SINGLETON == NULL){
    STCMAssembly assembly;
    if (parser(pathToXml, &assembly)){
      std::cout << assembly << std::endl;
      //bool inspectAssembly();
      SINGLETON = new Ordonnanceur(assembly);
    }
  }
  return SINGLETON;
}

/*
bool inspectConfigPort();
bool inspectInstances();
bool inspectComponents();
bool inspectDeclare();
bool inspectAssembly();
*/
