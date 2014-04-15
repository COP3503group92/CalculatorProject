#include "Pi.h"

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
			Pi* newPi = dynamic_cast<Pi*>(newCo->getNumerator());
			Add* add = new Add();
			this->exponent = add->evaluate(this->exponent, newPi->getExponent());
			newCo->setNumerator(newPi->getCoefficient());
			newCo->simplify();
			this->coefficient = newCo;
		}
		else if (newCo->getDenominator()->getType() == "Pi"){
			Pi* newPi = dynamic_cast<Pi*>(newCo->getDenominator());
			Subtract* sub = new Subtract();
			this->exponent = sub->evaluate(this->exponent, newPi->getExponent());
			newCo->setDenominator(newPi->getCoefficient());
			newCo->simplify();
			this->coefficient = newCo;
		}
		
	}
}

Number* Pi::getCoefficient(){
	return this->coefficient;
}

void Pi::setCoefficient(Number* coefficient){
	this->coefficient = coefficient;
}

string Pi::getType(){
	return this->typeName;
}

Number* Pi::getExponent(){
	return this->exponent;
}
void Pi::setExponent(Number* exponent){
	this->exponent = exponent;
}

string Pi::toString(){
	string str;
	if (this->coefficient->getType() != "Integer"){
		str += this->coefficient->toString();
	}
	else{
		Integer* co = dynamic_cast<Integer*>(this->coefficient);
		if (co->getValue() != 1){
			str += this->coefficient->toString();
		}
		else{

		}
	}
	if (this->exponent->getType() == "Integer"){
		Integer* exp = dynamic_cast<Integer*>(this->exponent);
		if (exp->getValue() == 0){
			return str;
		}
		else if (exp->getValue() == 1){
			str += "pi";
			return str;
		}

	}
	else{
		str += "(pi^";
		str += this->exponent->toString();
		str += ")";
		return str;
	}
}
bool Pi::operator==(Number* a){
	if (a->getType() == "Pi"){
		Pi* check = dynamic_cast<Pi*>(a);
		if (check->getCoefficient() == this->coefficient&& check->getExponent() == this->exponent){
			return true;
		}
	}
	return false;
	//Time permitting, check if a has a coefficient of a Pi type.
}

