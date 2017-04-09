#include "Instance.h"


Instance::Instance(const char* nameAttr,
  const char* componentRef,
  const char* path,
  const char* signature) :
  name(nameAttr), componentRef(componentRef), path(path), signature(signature){}


void Instance::print(std::ostream& os) const {
  os << "<Instance name='" << this->name << "', componentRef='" << this->componentRef << "', path='" << this->path << "', signature='" << this->signature << "'/>\n";
}

std::ostream &operator<<(std::ostream& os, const Instance &i){
  i.print(os);
  return os;
}
