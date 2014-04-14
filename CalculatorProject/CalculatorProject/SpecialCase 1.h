#pragma once

#include "Includes.h"

class SpecialCase:public Number {
public:
	virtual string toString();
	virtual ~SpecialCase();
	virtual void simplify();
	virtual string getType();
private:
	Number* coefficient;
	Number* power;
	string typeName;

};

#endif /* SPECIALCASE_H_ */
