#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include <Outport.h>
#include <Inport.h>

using namespace std;


class Component{
	private:
		string name;		//attribut
		Primitive primitive;//association
		InPort* inport;		//aggrégation
		OutPort* outport;	//aggrégation : hashmap ?
		

	public:
		bool setOutPort(OutPort outp);
		bool setInPort(InPort inp);
		OutPort getOutPort() const;
		InPort getInPort() const;
};


#endif
