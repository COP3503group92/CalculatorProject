/*
 * SpecialCase.h
 *
 *  Created on: Apr 5, 2014
 *      Author: mikeykem
 */

#ifndef SPECIALCASE_H_
#define SPECIALCASE_H_
#include "Number.h"
using namespace std;
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
