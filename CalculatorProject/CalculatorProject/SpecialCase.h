/*
 * SpecialCase.h
 *
 *  Created on: Apr 5, 2014
 *      Author: mikeykem
 */

#ifndef SPECIALCASE_H_
#define SPECIALCASE_H_
#include "Number.h"

class SpecialCase:public Number {
public:
	virtual string toString();
	virtual ~SpecialCase();
private:
	Number coefficient;
	Number power;

};

#endif /* SPECIALCASE_H_ */
