#include "Log.h"

Log::Log()
{
	this->coefficient = new Integer();
	this->exponent = new Integer();
	this->base = new Integer(10);
	this->operand = new Integer(3);
}


Log::~Log()
{
}

Log::Log(Number* base, Number* operand){
	this->coefficient = new Integer();
	this->exponent = new Integer();
	this->base = base;
	this->operand = operand;
}

Log::Log(Number* base, Number* operand, Number* coefficient, Number* exponent){
	this->base = base;
	this->coefficient = coefficient;
	this->exponent = exponent;
	this->operand = operand;
}

string Log::getType(){
	return this->typeName;
}

Number* Log::getCoefficient(){
	return this->coefficient;
}

Number* Log::getExponent(){
	return this->exponent;
}

Number* Log::getBase(){
	return this->base;
}

Number* Log::getOperand(){
	return this->operand;
}

void Log::setCoefficient(Number* co){
	this->coefficient = co;
}

void Log::setExponent(Number* ex){
	this->exponent = ex;
}

void Log::setBase(Number* ba){
	this->base = ba;
}
void Log::setOperand(Number* oper){
	this->operand = oper;
}