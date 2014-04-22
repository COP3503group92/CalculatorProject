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
	this->coefficient->simplify();
	this->operand->simplify();
	this->base->simplify();
	if (this->operand->getExponent()->getType() != "Integer"){
		Multiply* mult = new Multiply();
		this->coefficient = mult->evaluate(this->coefficient, this->operand->getExponent());
		this->operand->setExponent(new Integer(1));
	}
	else{
		Integer* opex = dynamic_cast<Integer*>(this->operand->getExponent());
		if (opex->getValue() != 0 && opex->getValue() != 1){
			Multiply* mult = new Multiply();
			this->coefficient = mult->evaluate(this->coefficient, this->operand->getExponent());
			this->operand->setExponent(new Integer(1));
		}
		else if (opex->getValue() == 1){
			if (this->operand->getType() == "Integer"){
				Integer* op = dynamic_cast<Integer*>(this->operand);
				Exponentiate* ex = new Exponentiate();
				for (int i = 2;; i++){
					for (int j = 2;; j++){
						Integer* sampInt = dynamic_cast<Integer*>(ex->evaluate(new Integer(i), new Integer(j)));
						if (op->getValue() < sampInt->getValue()){
							break;
						}
						if (op->getValue() == sampInt->getValue()){
							Multiply* mult = new Multiply();
							this->coefficient = mult->evaluate(this->coefficient, new Integer(j));
							this->operand = new Integer(i);
							break;
						}

						if (op->getValue() % sampInt->getValue() == 0 && op->getValue() != 0 && op->getValue() != 1){
							op->setValue(op->getValue() / sampInt->getValue());
							Multiply* mult = new Multiply();
							this->operand = op;
							this->complex.push_back(new Operator("+"));
							this->complex.push_back(new Log(this->base, new Integer(i), new Integer(j), new Integer()));
						}
					}
				}
			}

		}
	}
	if (this->base->getType() == "Integer"){
		Integer* ba = dynamic_cast<Integer*>(this->base);
		/*try{
			if (ba->getValue() == 0){
				throw invalid_argument("No 0 bases in logarithms!");
			}
		}*/
	}
	if (this->operand->getType() == "Rational"){
		Rational* op = dynamic_cast<Rational*>(operand);
		complex.push_back(new Operator("-"));
		complex.push_back(new Log(this->base, op->getDenominator(), this->coefficient, this->exponent));
		this->operand = op->getNumerator();
		simplify();
	}
	else if (this->operand->getType() == "Integer"&&this->base->getType() == "Integer"){
		Integer* op = dynamic_cast<Integer*>(this->operand);
		Integer* ba = dynamic_cast<Integer*>(this->base);
		if (op->getValue() < 0 && ba->getValue() % 2 == 0){
		}
		else{
			if (op->getValue() % ba->getValue() == 0){
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
	}
			else if (this->operand->getType() == "NatE"&& this->base->getType() == "NatE"){
				NatE* op = dynamic_cast<NatE*>(this->operand);
				complex.push_back(new Operator("+"));
				complex.push_back(op->getExponent());
				this->operand = op->getCoefficient();
			}
			else if (this->operand->getType() == "Pi"){
				Pi* op = dynamic_cast<Pi*>(this->operand);
				if (op->getCoefficient()->getType() == "Integer"){
					Integer* co = dynamic_cast<Integer*>(op->getCoefficient());
					if (co->getValue() != 1 && co->getValue() != 0){
						complex.push_back(new Operator("+"));
						complex.push_back(new Log(this->base, co, new Integer(), new Integer()));
						op->setCoefficient(new Integer());
						this->operand = op;
						simplify();
					}
				}
				else{
					complex.push_back(new Operator("+"));
					complex.push_back(new Log(this->base, op->getCoefficient(), new Integer(), new Integer()));
					op->setCoefficient(new Integer());
					this->operand = op;
					simplify();
				}
				if (op->getExponent()->getType() == "Integer"){
					Integer* ex = dynamic_cast<Integer*>(op->getExponent());
					if (ex->getValue() != 1 && ex->getValue() != 0){
						Multiply* mult = new Multiply();
						this->coefficient = mult->evaluate(this->coefficient, op->getExponent());
						op->setExponent(new Integer());
						this->operand = op;
					}
				}
				else{
					Multiply* mult = new Multiply();
					this->coefficient = mult->evaluate(this->coefficient, op->getExponent());
					op->setExponent(new Integer());
					this->operand = op;
				}

			}

			else if (this->operand->getType() == "NatE"){
				NatE* op = dynamic_cast<NatE*>(this->operand);
				if (op->getCoefficient()->getType() == "Integer"){
					Integer* co = dynamic_cast<Integer*>(op->getCoefficient());
					if (co->getValue() != 1 && co->getValue() != 0){
						complex.push_back(new Operator("+"));
						complex.push_back(new Log(this->base, co, new Integer(), new Integer()));
						op->setCoefficient(new Integer());
						this->operand = op;
						simplify();
					}
				}
				else{
					complex.push_back(new Operator("+"));
					complex.push_back(new Log(this->base, op->getCoefficient(), new Integer(), new Integer()));
					op->setCoefficient(new Integer());
					this->operand = op;
					simplify();
				}
				if (op->getExponent()->getType() == "Integer"){
					Integer* ex = dynamic_cast<Integer*>(op->getExponent());
					if (ex->getValue() != 1 && ex->getValue() != 0){
						Multiply* mult = new Multiply();
						this->coefficient = mult->evaluate(this->coefficient, op->getExponent());
						op->setExponent(new Integer());
						this->operand = op;
					}
				}
				else{
					Multiply* mult = new Multiply();
					this->coefficient = mult->evaluate(this->coefficient, op->getExponent());
					op->setExponent(new Integer());
					this->operand = op;
				}
			}
			else if (this->operand->getType() == "Root"){
				Root* op = dynamic_cast<Root*>(this->operand);
				if (op->getCoefficient()->getType() == "Integer"){
					Integer* co = dynamic_cast<Integer*>(op->getCoefficient());
					if (co->getValue() != 1 && co->getValue() != 0){
						complex.push_back(new Operator("+"));
						complex.push_back(new Log(this->base, co, new Integer(), new Integer()));
						op->setCoefficient(new Integer());
						this->operand = op;
						simplify();
					}
				}
				else{
					complex.push_back(new Operator("+"));
					complex.push_back(new Log(this->base, op->getCoefficient(), new Integer(), new Integer()));
					op->setCoefficient(new Integer());
					this->operand = op;
					simplify();
				}
				if (op->getExponent()->getType() == "Integer"){
					Integer* ex = dynamic_cast<Integer*>(op->getExponent());
					if (ex->getValue() != 1 && ex->getValue() != 0){
						Multiply* mult = new Multiply();
						this->coefficient = mult->evaluate(this->coefficient, op->getExponent());
						op->setExponent(new Integer());
						this->operand = op;
					}
				}
				else{
					Multiply* mult = new Multiply();
					this->coefficient = mult->evaluate(this->coefficient, op->getExponent());
					op->setExponent(new Integer());
					this->operand = op;
				}
				Multiply* mult = new Multiply();
				this->coefficient = mult->evaluate(this->coefficient, new Rational(new Integer(), op->getRoot()));
				op->setRoot(new Integer());
				this->operand = op;
			}
			else if (this->operand->getType() == "Expression"){
				Expression* op = dynamic_cast<Expression*>(this->operand);
				if (op->getCoefficient()->getType() == "Integer"){
					Integer* co = dynamic_cast<Integer*>(op->getCoefficient());
					if (co->getValue() != 1 || co->getValue() != 0){
						complex.push_back(new Operator("+"));
						complex.push_back(new Log(this->base, op->getCoefficient(), this->coefficient, this->exponent));
						op->setCoefficient(new Integer());
						this->operand = op;
						simplify();
					}
				}
			}
			for (int i = 0; i < complex.size(); i++){
				complex[i]->simplify();
			}
		}


bool Log::operator==(Number*a){
	a->simplify();
	simplify();
	if (a->getType() == "Log"){
		Log* b = dynamic_cast<Log*>(a);
		if (b->getBase() == this->base&&b->getCoefficient() == this->coefficient&& this->exponent == b->getExponent() 
			&& b->getOperand() == this->operand){
			vector<Number*> otherComp = b->getComplex();
			if (this->complex.size() == otherComp.size()){
				for (int i = 0; i < complex.size(); i++){
					if (complex[i] != otherComp[i]){
						return false;
					}
				}
				return true;
			}
		}
	}
	return false;
}
vector<Number*> Log::getComplex(){
	return this->complex;
}

string Log::toString(){
	string str;
	if (this->exponent->getType() != "Integer"){
		str += "((";
		str += this->coefficient->toString();
		str += "log_";
		str += this->base->toString();
		str += ":";
		str += this->operand->toString();
		for (int i = 0; i < this->complex.size()-1; i++){
			str += complex[i]->toString();
		}
		str += ")^";
		str += this->exponent->toString();
		str += ")";
	}
	else{
		Integer* a = dynamic_cast<Integer*>(this->exponent);
		if (a->getValue() != 0 && a->getValue() != 1){
			str += "((";
			str += this->coefficient->toString();
			str += "log_";
			str += this->base->toString();
			str += ":";
			str += this->operand->toString();
			for (int i = 0; i < this->complex.size(); i++){
				str += complex[i]->toString();
			}
			str += ")^";
			str += this->exponent->toString();
			str += ")";
		}
		else if(a->getValue() == 1){
			str += this->coefficient->toString();
			str += "log_";
			str += this->base->toString();
			str += ":";
			str += this->operand->toString();
			for (int i = 0; i < this->complex.size(); i++){
				str += complex[i]->toString();
			}
		}
		else{
			str = "1";
		}

	}
	return str;
}
