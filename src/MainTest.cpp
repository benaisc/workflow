#include <iostream>
#include "STCMAssembly.h"

int main(int argc, char* argv[]){
  STCMAssembly stcm;

  stcm.parse(argv[1]);

  stcm.print();
}
