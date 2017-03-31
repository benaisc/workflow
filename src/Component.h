#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include "OutPort.h"
#include "InPort.h"


class Component{
	private:
		string name;		//attribut
		InPort* inports;		//aggrégation : hashmap ?
		OutPort* outports;	//aggrégation
		//Attribute* attributes; //aggrégation

	public:
		bool addOutPort(OutPort outp);
		bool addInPort(InPort inp);
		OutPort* getOutPorts() const;
		InPort* getInPorts() const;
		//bool addAttribute(Attribute attr);
		//Attribute getAttributes() const;

		void print();
};


#endif
