#include "Root.h"


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
	if (this->operand->getType() == "Integer"&&this->root->getType()=="Integer"){
		Integer*op = dynamic_cast<Integer*>(this->operand);
		Exponentiate* ex = new Exponentiate();
		for (int i = 0;; i++){
			Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), this->root));
			if (op->getValue() < sampInt->getValue()){
				break;
			}
			if (op->getValue() % sampInt->getValue() == 0&& op->getValue()!=0&&op->getValue()!=1){
				op->setValue(op->getValue() / sampInt->getValue());
				Multiply* mult = new Multiply();
				this->operand = op;
				this->coefficient = mult->evaluate(new Integer(i), this->coefficient);
				simplify();
			}
		}
	}
	if (this->operand->getType() == "Rational"){
		Rational* op = dynamic_cast<Rational*>(this->operand);
		Rational * newRat = new Rational(new Root(op->getNumerator(), this->root, new Integer(), new Integer()));
		newRat->simplify();
		this->root = new Integer;
		this->operand = newRat;
	}
	if (this->operand->getType() == "Pi"){
		Pi* op = dynamic_cast<Pi*>(this->operand);
		if (op->getCoefficient()->getType() == "Integer"&&this->root->getType() == "Integer"){
			Integer*oper = dynamic_cast<Integer*>(op->getCoefficient());
			Exponentiate* ex = new Exponentiate();
			for (int i = 0;; i++){
				Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), this->root));
				if (oper->getValue() < sampInt->getValue()){
					break;
				}
				if (oper->getValue() % sampInt->getValue() == 0 && oper->getValue() != 0 && oper->getValue() != 1){
					oper->setValue(oper->getValue() / sampInt->getValue());
					Multiply* mult = new Multiply();
					op->setCoefficient(oper);
					this->coefficient = mult->evaluate(new Integer(i), this->coefficient);
					simplify();
				}
			}
		}
		if (op->getExponent()->getType() == "Integer"&& this->root->getType() == "Integer"){
			Integer* exp = dynamic_cast<Integer*>(op->getExponent());
			Integer* rt = dynamic_cast<Integer*>(this->root);
			if (exp->getValue() % rt->getValue()==0){
				Multiply* mult = new Multiply();
				this->operand = op->getCoefficient();
				this->coefficient = mult->evaluate(this->coefficient, new Pi(new Integer(), new Integer(exp->getValue() / rt->getValue())));
			}

		}
	}
	if (this->operand->getType() == "NatE"){
		NatE* op = dynamic_cast<NatE*>(this->operand);
		if (op->getCoefficient()->getType() == "Integer"&&this->root->getType()=="Integer"){
			Integer*oper = dynamic_cast<Integer*>(op->getCoefficient());
			Exponentiate* ex = new Exponentiate();
			for (int i = 0;; i++){
				Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), this->root));
				if (oper->getValue() < sampInt->getValue()){
					break;
				}
				if (oper->getValue() % sampInt->getValue() == 0 && oper->getValue() != 0 && oper->getValue() != 1){
					oper->setValue(oper->getValue() / sampInt->getValue());
					Multiply* mult = new Multiply();
					op->setCoefficient(oper);
					this->coefficient = mult->evaluate(new Integer(i), this->coefficient);
					simplify();
				}
			}
		}
		if (op->getExponent()->getType() == "Integer"&& this->root->getType()== "Integer"){
			Integer* exp = dynamic_cast<Integer*>(op->getExponent());
			Integer* rt = dynamic_cast<Integer*>(this->root);
			if (exp->getValue() % rt->getValue() == 0){
				Multiply* mult = new Multiply();
				this->operand = op->getCoefficient();
				this->coefficient = mult->evaluate(this->coefficient, new Pi(new Integer(), new Integer(exp->getValue() / rt->getValue())));
			}

		}
	}
	if (this->operand->getType() == "Log"){
		Log* op = dynamic_cast<Log*>(this->operand);
		if (op->getCoefficient()->getType() == "Integer"&&this->root->getType() == "Integer"){
			Integer*oper = dynamic_cast<Integer*>(op->getCoefficient());
			Exponentiate* ex = new Exponentiate();
			for (int i = 0;; i++){
				Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), this->root));
				if (oper->getValue() < sampInt->getValue()){
					break;
				}
				if (oper->getValue() % sampInt->getValue() == 0 && oper->getValue() != 0 && oper->getValue() != 1){
					oper->setValue(oper->getValue() / sampInt->getValue());
					Multiply* mult = new Multiply();
					op->setCoefficient(oper);
					this->coefficient = mult->evaluate(new Integer(i), this->coefficient);
					simplify();
				}
			}
		}
		if (op->getExponent()->getType() == "Integer"&& this->root->getType() == "Integer"){
			Integer* exp = dynamic_cast<Integer*>(op->getExponent());
			Integer* rt = dynamic_cast<Integer*>(this->root);
			if (exp->getValue() % rt->getValue() == 0){
				Multiply* mult = new Multiply();
				this->operand = op->getCoefficient();
				this->coefficient = mult->evaluate(this->coefficient, new Pi(new Integer(), new Integer(exp->getValue() / rt->getValue())));
			}

		}

	}
	if (this->operand->getType() == "Expression"){
		Expression* op = dynamic_cast<Expression*>(this->operand);
		if (op->getCoefficient()->getType() == "Integer"&&this->root->getType() == "Integer"){
			Integer*oper = dynamic_cast<Integer*>(op->getCoefficient());
			Exponentiate* ex = new Exponentiate();
			for (int i = 0;; i++){
				Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), this->root));
				if (oper->getValue() < sampInt->getValue()){
					break;
				}
				if (oper->getValue() % sampInt->getValue() == 0 && oper->getValue() != 0 && oper->getValue() != 1){
					oper->setValue(oper->getValue() / sampInt->getValue());
					Multiply* mult = new Multiply();
					op->setCoefficient(oper);
					this->coefficient = mult->evaluate(new Integer(i), this->coefficient);
					simplify();
				}
			}
		}
	}
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
	simplify();
	string str;
	if (this->exponent->getType() != "Integer"){
		str += "((";
		str += this->coefficient->toString();
		str += this->root->toString();
		str += "rt:";
		str += this->operand->toString();
		str += ")^";
		str += this->exponent->toString();
		str += ")";
	}
	else{
		Integer* a = dynamic_cast<Integer*>(this->exponent);
		if (a->getValue() != 0 && a->getValue() != 1){
			str += "((";
			str += this->coefficient->toString();
			str += this->root->toString();
			str += "rt:";
			str += this->operand->toString();
			str += ")^";
			str += this->exponent->toString();
			str += ")";
		}
		else if (a->getValue() == 1){
			str += this->coefficient->toString();
			str += this->root->toString();
			str += "rt:";
			str += this->operand->toString();
		}
		else{
			str = "1";
		}

	}
	return str;
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

Number* Root::getExponent(){
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
