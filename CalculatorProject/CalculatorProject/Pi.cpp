#include "Includes.h"


Pi::Pi()
{
	this->coefficient = new Integer();
	this->exponent = new Integer();
	this->negative = false;
}
Pi::Pi(Number* coefficient, Number* exponent){
	this->coefficient = coefficient;
	this->exponent = exponent;
	this->negative = false;
}
Pi::Pi(bool negative){
	if (negative == true){
		this->coefficient = new Integer(-1);
	}
	else{
		this->coefficient = new Integer();
	}
	this->exponent = new Integer();
}

Pi::~Pi()
{
}

void Pi::simplify(){
	this->exponent->simplify();
	this->coefficient->simplify();
	if (this->coefficient->getType() == "Rational"){
		Rational* newCo = dynamic_cast<Rational*>(this->coefficient);
		if (newCo->getNumerator()->getType() == "Pi"){
			Multiply* mult = new Multiply();

		}
	}
}

