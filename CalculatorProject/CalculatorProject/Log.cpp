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
void Log::simplify(){
	if (this->operand->getType() == "Rational"){
		Rational* op = dynamic_cast<Rational*>(operand);
		complex.push_back(new Operator("-"));
		complex.push_back(new Log(this->base, op->getDenominator(), this->coefficient, this->exponent));
		this->operand = op->getNumerator();
		simplify();
	}
	if (this->operand->getType() == "Integer"&&this->base->getType() == "Integer"){
		Integer* op = dynamic_cast<Integer*>(this->operand);
		Integer* ba = dynamic_cast<Integer*>(this->base);
		if (op->getValue() % ba->getValue()== 0){
			int bas = ba->getValue();
			int oper = op->getValue();
			int result = 0;
			while (oper%bas == 0){
				oper = oper / bas;
				result++;
			}
			op->setValue(oper);
			complex.push_back(new Operator("+"));
			complex.push_back(new Integer(result));
			this->operand = op;
			simplify();

		}
	}
	if (this->operand->getType() == "NatE"&& this->base->getType() == "NatE"){
		NatE* op = dynamic_cast<NatE*>(this->operand);
		NatE* ba = dynamic_cast<NatE*>(this->base);
		
	}
}