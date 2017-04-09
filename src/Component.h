#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "OutPort.h"
#include "InPort.h"
#include <list>

class Component{
	private:
		std::string name;		//attribut
		std::list<InPort> inports;		//aggrégation : liste ?
		std::list<OutPort> outports;	//aggrégation
		//Attribute* attributes; //aggrégation

	public:
		Component();
		Component(const char* nameAttr);
		Component(const Component &c);
		void addOutPort(OutPort outp);
		void addInPort(InPort inp);
		//std::list<OutPort>* getOutPorts() const;
		//std::list<InPort>* getInPorts() const;
		//bool addAttribute(Attribute attr);
		//Attribute getAttributes() const;

		void print(std::ostream& os) const;
};
std::ostream &operator<<(std::ostream& os, const Component &c);

#endif
