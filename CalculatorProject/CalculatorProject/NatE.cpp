#include "NatE.h"

NatE::NatE()
{
	this->coefficient = new Integer();
	this->exponent = new Integer(1);
	this->negative = false;
}


NatE::~NatE()
{
}

NatE::NatE(Number* coefficient, Number* exponent){
	this->coefficient = coefficient;
	this->exponent = exponent;
	this->negative = false;
}

NatE::NatE(bool negative){
	if (negative){
		this->coefficient = new Integer(-1);
	}
	else{
		this->coefficient = new Integer();
	}
	this->exponent = new Integer();
	this->negative = false;
}

string NatE::getType(){
	return this->typeName;
}

Number* NatE::getCoefficient(){
	return this->coefficient;
Number* getExponent();
void setExponent(Number* ex);
void setCoefficient(Number* co);
void simplify();
private:
	bool negative;
	Number* coefficient;
	Number* exponent;
	const string typeName = "NatE";
};