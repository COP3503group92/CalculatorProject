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
	if (this->root->getCoefficient()->getType() == "Integer"){
		Integer* rt = dynamic_cast<Integer*>(this->root->getCoefficient());
		if (rt->getValue() < 0){
			rt->setValue(rt->getValue()* -1);
			this->root = rt;
			Multiply* mult = new Multiply();
			this->exponent = mult->evaluate(this->exponent, new Integer(-1));
		}
	}
	else if (this->root->getCoefficient()->getType() == "Rational"){
		Rational* rt = dynamic_cast<Rational*>(this->root->getCoefficient());
		if (rt->getNumerator()->getCoefficient()->getType() == "Integer"){
			Integer* intt = dynamic_cast<Integer*>(rt->getNumerator()->getCoefficient());
			if (intt->getValue()<0){
				Multiply* mult = new Multiply();
				this->root = mult->evaluate(this->root, new Integer(-1));
				this->exponent = mult->evaluate(this->exponent, new Integer(-1));
			}
		}
	}
	if (this->operand->getType() == "Integer"&&this->root->getType()=="Integer"){
		Integer*op = dynamic_cast<Integer*>(this->operand);
		Exponentiate* ex = new Exponentiate();
		for (int i = 1;; i++){
			Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), this->root));
			if (abs(op->getValue()) < sampInt->getValue()){
				break;
			}
			if (abs(op->getValue()) % sampInt->getValue() == 0&& op->getValue()!=0&&op->getValue()!=1){
				op->setValue(op->getValue() / sampInt->getValue());
				Multiply* mult = new Multiply();
				this->operand = op;
				this->coefficient = mult->evaluate(new Integer(i), this->coefficient);
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
	string str = "";
	if (dynamic_cast<Integer*>(this->operand) == 0){
		if (this->exponent->getType() != "Integer"){
			str += "((";
			str += this->coefficient->toString();
			str += "(";
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
				str += "(";
				str += this->root->toString();
				str += "rt:";
				str += this->operand->toString();
				str += ")";
			}
			else{
				str = "1";
			}

		}
	}
	else{
		Integer* op = dynamic_cast<Integer*>(this->operand);
		if (op->getValue() != 0 && op->getValue() != 1 && op->getValue() != -1){
			if (this->exponent->getType() != "Integer"){
				str += "((";
				str += this->coefficient->toString();
				str += "(";
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
					str += "(";
					str += this->root->toString();
					str += "rt:";
					str += this->operand->toString();
					str += ")";
				}
				else{
					str = "1";
				}
			}
		}
		else if (op->getValue() == 1){
			if (this->exponent->getType() == "Integer"){
				Integer* exp = dynamic_cast<Integer*>(this->exponent);
				if (exp->getValue() < 0){
					str += "(1/" + this->coefficient->toString() + ")";
				}

				else{
					str += this->coefficient->toString();
				}
			}
			else if (op->getValue() == -1){
				if (this->root->getType() != "Integer"){
					str += "(" + this->coefficient->toString();
					str += "(" + this->root->toString() + "rt:";
					str += op->toString() + ")";
					if (this->exponent->getType() != "Integer"){
						str += "^" + this->exponent->toString() + ")";
					}
				}
				else{
					Integer* root = dynamic_cast<Integer*>(this->root);
					if (root->getValue() != 0 && root->getValue() != 1){
						if (root->getValue() % 2 == 0){
							str += "(" + this->coefficient->toString();
							str += "(i)";
							if (this->exponent->getType() != "Integer"){
								str += "^" + this->exponent->toString();
							}
							else{
								Integer* a = dynamic_cast<Integer*>(this->exponent);
								if (a->getValue() != 0 && a->getValue() != 1){
									str += "^" + this->exponent->toString();
								}
								else if (a->getValue() == 1){
									str += ")";
								}
								else{
									str = this->coefficient->toString();
								}
							}
						}
						else{
							Multiply* mult = new Multiply();
							this->coefficient = mult->evaluate(this->coefficient, new Integer(-1));
							str += this->coefficient->toString();
						}
					}
				}
			}

		}

		return str;
	}
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

bool Root::operator==(Number* a){
	if (a->getType() == this->typeName){
		Root* other = dynamic_cast<Root*>(a);
		if (other->getCoefficient()==this->coefficient&&other->getExponent()==this->exponent&& 
			other->getOperand() == this->operand&&other->getRoot() == this->root){
			return true;
		}
	}
	return false;
}