#include <iostream>
#include "LibParser.h"

int main(int argc, char* argv[]){
  STCMAssembly stcm;

  parser(argv[1], &stcm);

  std::cout << stcm << std::endl;

  return(0);
}
