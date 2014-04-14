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
}

Number* NatE::getExponent(){
	return this->exponent;
}

void NatE::setExponent(Number* ex){
	this->exponent = ex;
}

void NatE::setCoefficient(Number* co){
	this->coefficient = co;
}
void NatE::simplify(){
	this->exponent->simplify();
	this->coefficient->simplify();
	if (this->coefficient->getType() == "Rational"){
		Rational* newCo = dynamic_cast<Rational*>(this->coefficient);
		if (newCo->getNumerator()->getType() == "NatE"){
			NatE* newPi = dynamic_cast<NatE*>(newCo->getNumerator());
			Add* add = new Add();
			this->exponent = add->evaluate(this->exponent, newPi->getExponent());
			newCo->setNumerator(newPi->getCoefficient());
			newCo->simplify();
			this->coefficient = newCo;
		}
		else if (newCo->getDenominator()->getType() == "NatE"){
			NatE* newPi = dynamic_cast<NatE*>(newCo->getDenominator());
			Subtract* sub = new Subtract();
			this->exponent = sub->evaluate(this->exponent, newPi->getExponent());
			newCo->setDenominator(newPi->getCoefficient());
			newCo->simplify();
			this->coefficient = newCo;
		}

	}
}

bool NatE::operator==(Number* a){
	if (a->getType() == "NatE"){
		NatE* check = dynamic_cast<NatE*>(a);
		if (check->getCoefficient() == this->coefficient&& check->getExponent == this->exponent){
			return true;
		}
	}
	return false;
	//Time permitting, check a for a coefficient of type NatE.
}
string NatE::toString(){
	string str;
	str += this->coefficient->toString();
	if (this->exponent->getType() == "Integer"){
		Integer* exp = dynamic_cast<Integer*>(this->exponent);
		if (exp->getValue() == 0){
			return str;
		}
		else if (exp->getValue() == 1){
			str += "e";
			return str;
		}

	}
	else{
		str += "(e^";
		str += this->exponent->toString();
		str += ")";
		return str;
	}
}