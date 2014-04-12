/*
 * Number.h
 *
 *  Created on: Apr 5, 2014
 *      Author: mikeykem
 */

#ifndef NUMBER_H_
#define NUMBER_H_
#include <string>
using namespace std;
class Number {
public:
	virtual ~Number();
	//Considering returning a Number* for below. Let Rationals with Pi numerators
	//become Pis with rational coefficients.
	virtual void simplify(); 
	virtual string getType();
private:
	string typeName;
};

#endif /* NUMBER_H_ */
