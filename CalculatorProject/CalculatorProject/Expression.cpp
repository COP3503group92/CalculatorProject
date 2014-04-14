#include "Expression.h"

Expression::Expression()
{
}


Expression::~Expression()
{
}

void Expression::add(Number* first, Number* second, Number* op){
	this->expr.push_back(first);
	this->expr.push_back(op);
	this->expr.push_back(second);
}
string Expression::getType(){
	return this->typeName;
}

vector<Number*> Expression::getExpression(){
	return this->expr;
}
void Expression::setExpression(vector<Number*> expr){
	this->expr = expr;
}
Number* Expression::getCoefficient(){
	return this->coefficent;
}

void Expression::setCoefficient(Number* coef){
	this->coefficent = coef;
}
Number* Expression::getExponent(){
	return this->exponent;
}
void Expression::setExponent(Number* exp){
	this->exponent = exp;
}
string Expression::toString(){
	string str = "";
	str += this->coefficent->toString();
	str += "(";
	for (int i = 0; i < expr.size(); i++){
		str += expr[i]->toString();
	}
	str += this->exponent->toString();
	return str;
}
bool Expression::operator==(Number* a){
	if (a->getType() == this->typeName){
		Expression* exp = dynamic_cast<Expression*>(a);
		if (exp->getCoefficient() == this->coefficent&&this->exponent==exp->getExponent()){
			vector<Number*>other = exp->getExpression();
			if (other.size() == this->expr.size()){
				for (int i = 0; i < other.size(); i++){
					if (other[i] != this->expr[i]){
						return false;
					}
				}
				return true;
			}
		}
	}
	return false;
}
void Expression::simplify(){
	this->coefficent->simplify();
	Number* common = this->expr[0]->getCoefficient();
	int count;
	int opCount;
	for (int j = 0; j < this->expr.size() - 1; j++){
		count = 0;
		opCount = 0;
		Rational* rat = new Rational(common, expr[j]->getCoefficient());
		rat->simplify();
		if (rat->getDenominator()->getType() == "Integer"){
			Integer* den = dynamic_cast<Integer*>(rat->getDenominator());
			if (den->getValue() != 1){
				break;
			}

		}
		else if (rat->getDenominator()->getType() == "Operator"){
			opCount++;
		}
		else{
			count++;
		}
		if (opCount + count == this->expr.size()){
			this->coefficent = common;
			for (int j = 0; j < this->expr.size() - 1; j++){
				Rational* rat = new Rational(this->expr[j]->getCoefficient(), common);
				rat->simplify();
				this->expr[j]->setCoefficient(rat);

			}
		}
	}
	for (int i = 0; i < this->expr.size() - 1; i++){
		this->expr[i]->simplify();
	}
}
				