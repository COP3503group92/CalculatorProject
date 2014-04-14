#include "Number.h"
#include "Integer.h"

Number::~Number() {
	// TODO Auto-generated destructor stub
}

void Number::simplify(){

}

string Number::getType(){
	return "VisualStudios is stupid sometimes.";
}

string Number::toString(){
	return "Herp derp.";
}

bool Number::operator==(Number* a){
	return true;
}
Number* Number::getCoefficient(){
	return new Integer();
}
virtual Number* getExponent();
virtual void setExponent(Number* exp);
virtual void setCoefficient(Number* coef);