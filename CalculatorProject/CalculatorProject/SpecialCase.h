/*
 * SpecialCase.h
 *
 *  Created on: Apr 5, 2014
 *      Author: mikeykem
 */

#ifndef SPECIALCASE_H_
#define SPECIALCASE_H_
#include <string>
using namespace std;

class SpecialCase:public Number {
public:
	virtual SpecialCase();
	virtual string toString();
	virtual ~SpecialCase();
private:
	Number coefficient;
	Number power;

};

#endif /* SPECIALCASE_H_ */
