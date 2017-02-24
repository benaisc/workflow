#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include <string.h>

using namespace std;


class Primitive{
	private:
		string lang;
		string path;
		string signature;

	public:
		Primitive(string language, string execpath, string command);
		string getLang() const;
		string getPath() const;
		string getSignature() const;
};


#endif
