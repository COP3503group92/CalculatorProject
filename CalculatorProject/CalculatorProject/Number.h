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
	//May need to consider having an == overload for every class.
	virtual void simplify(); 
	virtual string getType();
	virtual string toString();
private:
	string typeName;
};

#endif /* NUMBER_H_ */
