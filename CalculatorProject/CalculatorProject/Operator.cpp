#include "Operator.h"

Operator::Operator()
{
	this->op = "+";
}


Operator::~Operator()
{
}

Operator::Operator(string oper){
	this->op = oper;
}

string Operator::getOperator(){
	return this->op;
}

string Operator::getType(){
	return typeName;
}

string Operator::toString(){
	return " "+this->op+ " ";
}
void Operator::simplify(){
}
bool Operator::operator==(Number* a){
	if (a->getType() == "Operator"){
		Operator* b = dynamic_cast<Operator*>(a);
		if (b->getOperator() == this->op){
			return true;
		}
	}
	return false;
}
Number* Operator::getCoefficient(){
	return this;
}
Number* Operator::getExponent(){
	return this;
}
void Operator::setExponent(Number* exp){

}
void Operator::setCoefficient(Number coef){

}

