#include "LibParser.h"

void usage(){
	printf("Usage: %s <path_to_assemblyXML>", argv[0]);
}
int main(int argc, char* argv[]){
  STCMAssembly stcm;

  if(argc < 2){
	usage();
	exit(-1);
  }
  parser(argv[1], &stcm);

  std::cout << stcm << std::endl;

  return(0);
}
