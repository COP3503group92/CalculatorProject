#include "Includes.h"


Root::Root()
{
	this->coefficient = new Integer();
	this->exponent = new Integer();
	this->operand = new Integer(2);
	this->root = new Integer(2);
}


Root::~Root()
{
}

Root::Root(Number* operand, Number* root, Number* coefficient, Number* exponent){
	this->coefficient = coefficient;
	this->exponent = exponent;
	this->operand = operand;
	this->root = root;
}
void Root::simplify(){	
	
}
Root::Root(Number* operand, Number* root){
	this->operand = operand;
	this->root = root;
	this->coefficient = new Integer();
	this->exponent = new Integer();
}

string Root::getType(){
	return this->typeName;
}

string Root::toString(){

}
Number* Root::getRoot(){
	return this->root;
}

Number* Root::getCoefficient(){
	return this->coefficient;
}

Number* Root::getOperand(){
	return this->operand;
}

Number* Root::getexponent(){
	return this->exponent;
}

void Root::setRoot(Number* root){
	this->root = root;
}

void Root::setOperand(Number* oper){
	this->operand = oper;
}

void Root::setCoefficient(Number* coef){
	this->coefficient = coef;
}

void Root::setExponent(Number* exp){
	this->exponent = exp;
}
