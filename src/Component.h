#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include "OutPort.h"
#include "InPort.h"
#include <list>

class Component{
	private:
		string name;		//attribut
		std::list<InPort> inports;		//aggrégation : liste ?
		std::list<OutPort> outports;	//aggrégation
		//Attribute* attributes; //aggrégation

	public:
		Component(string name);
		void addOutPort(OutPort outp);
		void addInPort(InPort inp);
		std::list<OutPort>* getOutPorts() const;
		std::list<InPort>* getInPorts() const;
		//bool addAttribute(Attribute attr);
		//Attribute getAttributes() const;

		void print();
};


#endif
