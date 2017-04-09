#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#include "STCMAssembly.h"

int main(int argc, char* argv[]){
  STCMAssembly stcm;

  if (stcm.parse(argv[1]))
    std::cout << stcm << std::endl;
  else
    std::cout << "Erreur :(\n";

  return(0);
}
