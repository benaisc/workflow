#ifndef __INSTANCE_H__
#define __INSTANCE_H__

#include "Component.h"

class Instance{
	private:
		std::string name;
		std::string componentRef;
		std::string path;
		std::string signature;

	public:
		Instance(){}
		Instance(const char* nameAttr, const char* componentRef, const char* path, const char* signature);

		void print(std::ostream& os) const;
};

std::ostream &operator<<(std::ostream& os, const Instance &i);
#endif
