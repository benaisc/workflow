#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include "Outport.h"
#include "Inport.h"


class Component{
	private:
		string name;		//attribut
		Primitive primitive;//association
		InPort* inports;		//aggrégation : hashmap ?
		OutPort* outports;	//aggrégation
		Attribute* attributes; //aggrégation

	public:
		bool addOutPort(OutPort outp);
		bool addInPort(InPort inp);
		OutPort* getOutPorts() const;
		InPort* getInPorts() const;
		bool addAttribute(Attribute attr);
		Attribute getAttributes() const;
};


#endif
