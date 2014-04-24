#include "Expression.h"

Expression::Expression()
{
	this->coefficent = new Integer();
	this->exponent = new Integer();
	this->expr;
}


Expression::~Expression()
{
}

void Expression::add(Number* first){
	this->expr.push_back(new Operator("+"));
	this->expr.push_back(first);
}

void Expression::add(Number* first, Number* second, Number* op){
	this->expr.push_back(new Operator("+"));
	this->expr.push_back(first);
	this->expr.push_back(op);
	this->expr.push_back(second);
	this->coefficent = new Integer();
	this->exponent = new Integer();
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
	if (this->coefficent->getType() == "Integer"){
		Integer* co = dynamic_cast<Integer*>(this->coefficent);
		if (co->getValue() != 1){
			str += this->coefficent->toString();
			str += "(";
			for (int i = 0; i < expr.size(); i++){
				str += expr[i]->toString();
			}
			
		}
		else {
			str += "(";
			for (int i = 0; i < expr.size(); i++){
				str += expr[i]->toString();
			}
			
		}
	}
	else{
		str += this->coefficent->toString();
		str += "(";
		for (int i = 0; i < expr.size(); i++){
			str += expr[i]->toString();
		}
	}

	if (this->exponent->getType() == "Integer"){
		Integer* ex = dynamic_cast<Integer*>(this->exponent);
		if (ex->getValue() != 1){
			str += ")";
			str += "^";
			str += this->exponent->toString();
		}
		else{
			str += ")";
		}
	}
	else{
		str += ")";
		str += "^";
		str += this->exponent->toString();

	}
	for (int i = 0; i < str.size(); i++){
		if (str.at(i) == '0'){
			if (str.at(i - 1) == '('){
				str.erase(i, 1);
			}
			else{
				str.erase(i - 1, 2);
			}
		}
	}
	for (int i = 0; i < str.size(); i++){
		if (str.at(i) == '+'){
			if (str.at(i - 1) == '('){
				str.erase(i, 1);
			}
		}
	}
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
	Number* common = this->expr[1]->getCoefficient();
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
	for (int i = 0; i < this->expr.size(); i++){
		if (this->expr[i]->getType() == "Operator"){
			Operator* opera = dynamic_cast<Operator*>(this->expr[i]);
			if (opera->getOperator() == "-"){
				this->expr[i] = new Operator("+");
				Multiply mult = Multiply();
				this->expr[i + 1] = mult.evaluate(this->expr[i + 1], new Integer(-1));
			}
			this->expr[i]->simplify();
		}
	}
}
				