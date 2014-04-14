#include "Rational.h"


Rational::Rational(){
	this->numerator = new Integer(1);
	this->denominator = new Integer(2);
}

Rational::Rational(Number* numerator){
	this->numerator = numerator;
	this->denominator = new Integer(1);
}

Rational::Rational(Number* numerator, Number* denominator){
	this->numerator = numerator;
	this->denominator = denominator;
}
Rational::~Rational() {
		this->numerator->~Number();
		this->denominator->~Number();
}

void Rational::simplify(){
	if (this->denominator->getType() == "Integer"){
		Integer* denom = dynamic_cast<Integer*>(this->denominator);
		if (denom->getValue == 1){
			return;
		}
	}
	if (this->numerator->getType() == this->denominator->getType()){
		if (this->numerator->getType() == "Integer"){
			Integer* numer = dynamic_cast<Integer*>(this->numerator);
			Integer* denom = dynamic_cast<Integer*>(this->denominator);
			int num = numer->getValue();
			int den = denom->getValue();
			int& n = num;
			int& d = den;
			leastCommonDenom(n, d);
			numer->setValue(num);
			denom->setValue(den);
			this->numerator = numer;
			this->denominator = denom;
		}
		else if (this->numerator->getType() == "Rational")
		{
			Rational* rat1 = dynamic_cast<Rational*>(this->numerator);
			Rational* rat2 = dynamic_cast<Rational*>(this->denominator);
			Multiply* numMult = new Multiply();
			setNumerator(numMult->evaluate(rat1->getNumerator(), rat2->getDenominator()));
			setDenominator(numMult->evaluate(rat1->getDenominator(), rat2->getNumerator()));
			simplify();
		}
		else if (this->numerator->getType() == "Pi"){
			Pi* firstPi = dynamic_cast<Pi*>(this->numerator);
			Pi* secondPi = dynamic_cast<Pi*>(this->denominator);
			Rational* newCo = new Rational(firstPi->getCoefficient(), secondPi->getCoefficient());
			Subtract* exSub = new Subtract();
			Number* newEx = exSub->evaluate(firstPi->getExponent(), secondPi->getExponent());
			newEx->simplify();
			newCo->simplify();
			Pi* answer = new Pi();
			answer->setExponent(newEx);
			answer->setCoefficient(newCo);
			this->numerator = answer;
			this->denominator = new Integer();
		}
		else if (this->numerator->getType() == "NatE"){
			NatE* firstE = dynamic_cast<NatE*>(this->numerator);
			NatE* secondE = dynamic_cast<NatE*>(this->denominator);
			Rational* newCo = new Rational(firstE->getCoefficient(), secondE->getCoefficient());
			Subtract* exSub = new Subtract();
			Number* newEx = exSub->evaluate(firstE->getExponent(), secondE->getCoefficient());
			newEx->simplify();
			newCo->simplify();
			NatE* answer = new NatE();
			answer->setCoefficient(newCo);
			answer->setExponent(newEx);
			this->numerator = answer;
			this->denominator = new Integer();
		}
		else if (this->numerator->getType() == "Log"){
			Log* numLog = dynamic_cast<Log*>(this->numerator);
			Log* denomLog = dynamic_cast<Log*>(this->denominator);
			if (numLog->getBase() == denomLog->getBase()){
				Rational* newCo = new Rational(numLog->getCoefficient(), denomLog->getCoefficient());
				newCo->simplify();
				numLog->setCoefficient(newCo);
				numLog->setBase(denomLog->getOperand());
				this->numerator = numLog;
				this->denominator = new Integer();
			}
			Rational* newCo = new Rational(numLog->getCoefficient(), denomLog->getCoefficient());
			newCo->simplify();
			numLog->setCoefficient(newCo);
			denomLog->setCoefficient(new Integer());
			this->numerator = numLog;
			this->denominator = denomLog;
		}
		else if (this->numerator->getType() == "Root"){
			Root* newNum = dynamic_cast<Root*>(this->numerator);
			Root* newDenom = dynamic_cast<Root*>(this->denominator);
			newNum->simplify();
			newDenom->simplify();
			if (newNum->getRoot() == newDenom->getRoot()){
				Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
				newCo->simplify();
				Rational* newOp = new Rational(newNum->getOperand, newDenom->getOperand);
				newOp->simplify();
				newNum->setCoefficient(newCo);
				newNum->setOperand(newOp);
				this->numerator = newNum;
				this->denominator = new Integer();
			}
			Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
			newCo->simplify();
			newNum->setCoefficient(newCo->getNumerator());
			newDenom->setCoefficient(newCo->getDenominator());
			Multiply* mult = new Multiply();
			Number* newerNum = mult->evaluate(newNum, newDenom);
			Number* newerDenom = mult->evaluate(newDenom, newDenom);
			newerNum->simplify();
			newerDenom->simplify();
			this->numerator = newerNum;
			this->denominator = newerDenom;
		}
		else if (this->numerator->getType() == "Expression"){


		}
	}//End same-type check
	else if (this->numerator->getType() == "Integer"&&this->denominator->getType() == "Rational"){
		Integer* newNum = dynamic_cast<Integer*>(this->numerator);
		Rational* newDenom = dynamic_cast<Rational*>(this->denominator);
		Multiply* mult = new Multiply();
		Number* newerNum = mult->evaluate(newNum, newDenom->getDenominator());
		this->denominator = newDenom->getNumerator();
		this->numerator = newerNum;
	}
	else if (this->numerator->getType() == "Integer"&&this->denominator->getType() == "Pi"){
		Integer* newNum = dynamic_cast<Integer*>(this->numerator);
		Pi* newDenom = dynamic_cast<Pi*>(this->denominator);
		Rational* toSimp = new Rational(newNum, newDenom->getCoefficient());
		toSimp->simplify();
		newDenom->setCoefficient(toSimp->getDenominator());
		this->numerator = toSimp->getNumerator();
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Integer"&&this->denominator->getType() == "NatE"){
		Integer* newNum = dynamic_cast<Integer*>(this->numerator);
		NatE* newDenom = dynamic_cast<NatE*>(this->denominator);
		Rational* toSimp = new Rational(newNum, newDenom->getCoefficient());
		toSimp->simplify();
		newDenom->setCoefficient(toSimp->getDenominator());
		this->numerator = toSimp->getNumerator();
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Integer"&&this->denominator->getType() == "Log"){
		Integer* newNum = dynamic_cast<Integer*>(this->numerator);
		Log* newDenom = dynamic_cast<Log*>(this->denominator);
		Rational* toSimp = new Rational(newNum, newDenom->getCoefficient());
		toSimp->simplify();
		newDenom->setCoefficient(toSimp->getDenominator());
		this->numerator = toSimp->getNumerator();
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Integer"&&this->denominator->getType() == "Root"){
		Integer* newNum = dynamic_cast<Integer*>(this->numerator);
		Root* newDenom = dynamic_cast<Root*>(this->denominator);
		Multiply* mult = new Multiply();		
		Exponentiate* exp = new Exponentiate();
		Subtract* sub = new Subtract();
		Number* newerNum = mult->evaluate(newNum, exp->evaluate(newDenom, sub->evaluate(newDenom->getRoot(), new Integer())));
		Number* newerDenom = exp->evaluate(newDenom, newDenom->getRoot);
		newerNum->simplify();
		newerDenom->simplify();
		simplify();
	}
	else if (this->numerator->getType() == "Integer"&&this->denominator->getType() == "Expression"){

	}
	else if (this->numerator->getType() == "Rational"&& this->denominator->getType() == "Integer"){
		Rational* newNum = dynamic_cast<Rational*>(this->numerator);
		Integer* newDenom = dynamic_cast<Integer*>(this->denominator);
		Multiply* mult = new Multiply();
		this->numerator = mult->evaluate(newNum->getNumerator(), newDenom);
		this->denominator = newNum->getDenominator();
	}
	else if (this->numerator->getType() == "Rational"&& this->denominator->getType() == "Pi"){
		Rational* newNum = dynamic_cast<Rational*>(this->numerator);
		Pi* newDenom = dynamic_cast<Pi*>(this->denominator);
		Multiply* mult = new Multiply();
		this->numerator = mult->evaluate(newNum->getNumerator(), newDenom);
		this->denominator = newNum->getDenominator();
	}
	else if (this->numerator->getType() == "Rational"&&this->denominator->getType() == "NatE"){
		Rational* newNum = dynamic_cast<Rational*>(this->numerator);
		NatE* newDenom = dynamic_cast<NatE*>(this->denominator);
		Multiply* mult = new Multiply();
		this->numerator = mult->evaluate(newNum->getNumerator(), newDenom);
		this->denominator = newNum->getDenominator();
	}
	else if (this->numerator->getType() == "Rational"&&this->denominator->getType() == "Log"){
		Rational* newNum = dynamic_cast<Rational*>(this->numerator);
		Log* newDenom = dynamic_cast<Log*>(this->denominator);
		Multiply* mult = new Multiply();
		this->numerator = mult->evaluate(newNum->getNumerator(), newDenom);
		this->denominator = newNum->getDenominator();
	}
	else if (this->numerator->getType() == "Rational"&&this->denominator->getType() == "Root"){
		Rational* newNum = dynamic_cast<Rational*>(this->numerator);
		Root* newDenom = dynamic_cast<Root*>(this->denominator);
		Multiply* mult = new Multiply();
		this->numerator = mult->evaluate(newNum->getNumerator(), newDenom);
		this->denominator = newNum->getDenominator();
	}
	else if (this->numerator->getType() == "Rational"&&this->denominator->getType() == "Expression"){

	}
	else if (this->numerator->getType() == "Pi"&& this->denominator->getType() == "Integer"){
		Pi* newNum = dynamic_cast<Pi*>(this->numerator);
		Integer* newDenom = dynamic_cast<Integer*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom);
		newCo->simplify();
		newNum->setCoefficient(newCo);
		this->numerator = newNum;
		this->denominator = new Integer();
	}
	else if (this->numerator->getType() == "Pi"&& this->denominator->getType() == "Rational"){
		Pi* newNum = dynamic_cast<Pi*>(this->numerator);
		Rational* newDenom = dynamic_cast<Rational*>(this->denominator);
		Rational* newerDenom = new Rational(newDenom->getDenominator(), newDenom->getNumerator());
		Multiply* mult = new Multiply();
		newNum->setCoefficient(mult->evaluate(newerDenom->getNumerator, newNum->getCoefficient()));
		this->numerator = newNum;
		this->denominator = newerDenom->getDenominator();
	}
	else if (this->numerator->getType() == "Pi"&& this->denominator->getType() == "NatE"){
		Pi* newNum = dynamic_cast<Pi*>(this->numerator);
		NatE* newDenom = dynamic_cast<NatE*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator());
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Pi"&& this->denominator->getType() == "Log"){
		Pi* newNum = dynamic_cast<Pi*>(this->numerator);
		Log* newDenom = dynamic_cast<Log*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator());
		this->numerator = newNum;
		this->denominator = newDenom;

	}
	else if (this->numerator->getType() == "Pi"&&this->denominator->getType() == "Root"){
		Pi* newNum = dynamic_cast<Pi*>(this->numerator);
		Root* newDenom = dynamic_cast<Root*>(this->denominator);
		Multiply* mult = new Multiply();
		Number* newerNum = mult->evaluate(newNum, newDenom);
		Number* newerDenom = mult->evaluate(newDenom, newDenom);
		newerNum->simplify();
		newerDenom->simplify();
		this->numerator = newerNum;
		this->denominator = newerDenom;
		simplify();
	}
	else if (this->numerator->getType() == "Pi"&&this->denominator->getType() == "Expression"){

	}
	else if (this->numerator->getType() == "NatE"&&this->denominator->getType() == "Integer"){
		NatE* newNum = dynamic_cast<NatE*>(this->numerator);
		Integer* newDenom = dynamic_cast<Integer*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom);
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		this->numerator = newNum;
		this->denominator = newCo->getDenominator();
	}
	else if (this->numerator->getType() == "NatE"&&this->denominator->getType() == "Rational"){
		NatE* newNum = dynamic_cast<NatE*>(this->numerator);
		Rational* newDenom = dynamic_cast<Rational*>(this->denominator);
		Rational* newerDenom = new Rational(newDenom->getDenominator(), newDenom->getNumerator());
		Multiply* mult = new Multiply();
		newNum->setCoefficient(mult->evaluate(newerDenom, newNum->getCoefficient()));
		this->numerator = newNum;
		this->denominator = new Integer();
	}
	else if (this->numerator->getType() == "NatE" && this->denominator->getType() == "Pi"){
		NatE* newNum = dynamic_cast<NatE*>(this->numerator);
		Pi* newDenom = dynamic_cast<Pi*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator());
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "NatE"&&this->denominator->getType() == "Log"){
		NatE* newNum = dynamic_cast<NatE*>(this->numerator);
		Log* newDenom = dynamic_cast<Log*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator());
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "NatE"&& this->denominator->getType() == "Root"){
		NatE* newNum = dynamic_cast<NatE*>(this->numerator);
		Root* newDenom = dynamic_cast<Root*>(this->denominator);
		Multiply* mult = new Multiply();
		Number* newerNum = mult->evaluate(newNum, newDenom);
		Number* newerDenom = mult->evaluate(newDenom, newDenom);
		newerNum->simplify();
		newerDenom->simplify();
		this->numerator = newerNum;
		this->denominator = newerDenom;
		simplify();
	}
	else if (this->numerator->getType() == "NatE"&& this->denominator->getType() == "Expression"){

	}
	else if (this->numerator->getType() == "Log"&&this->denominator->getType() == "Integer"){
		Log* newNum = dynamic_cast<Log*>(this->numerator);
		Integer* newDenom = dynamic_cast<Integer*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom);
		newCo->simplify();
		newNum->setCoefficient(newCo);
		this->numerator = newNum;
		this->denominator = new Integer();
	}
	else if (this->numerator->getType() == "Log"&& this->denominator->getType() == "Rational"){
		Log* newNum = dynamic_cast<Log*>(this->numerator);
		Rational* newDenom = dynamic_cast<Rational*>(this->denominator);
		Rational* newerDenom = new Rational(newDenom->getDenominator(), newDenom->getNumerator());
		Multiply* mult = new Multiply();
		newNum->setCoefficient(mult->evaluate(newNum->getCoefficient(), newerDenom->getNumerator()));
		this->numerator = newNum;
		this->denominator = newerDenom->getDenominator();
	}
	else if (this->numerator->getType() == "Log"&& this->denominator->getType() == "Pi"){
		Log* newNum = dynamic_cast<Log*>(this->numerator);
		Pi* newDenom = dynamic_cast<Pi*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator());
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Log"&& this->denominator->getType() == "NatE"){
		Log* newNum = dynamic_cast<Log*>(this->numerator);
		NatE* newDenom = dynamic_cast<NatE*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator());
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Log"&&this->denominator->getType() == "Root"){
		Log* newNum = dynamic_cast<Log*>(this->numerator);
		Root* newDenom = dynamic_cast<Root*>(this->denominator);
		Multiply* mult = new Multiply();
		Number* newerNum = mult->evaluate(newNum, newDenom);
		Number* newerDenom = mult->evaluate(newDenom, newDenom);
		newerNum->simplify();
		newerDenom->simplify();
		this->numerator = newerNum;
		this->denominator = newerDenom;
		simplify();
	}
	else if (this->numerator->getType() == "Log"&& this->denominator->getType() == "Expression"){

	}
	//GO BACK AND CHANGE ROOT IN DENOMINATOR CASES!!!!!!!
	else if (this->numerator->getType() == "Root"&&this->denominator->getType() == "Integer"){
		Root* newNum = dynamic_cast<Root*>(this->numerator);
		Integer* newDenom = dynamic_cast<Integer*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom);
		newCo->simplify();
		newNum->setCoefficient(newCo);
		this->numerator = newNum;
		this->denominator = new Integer();
	}
	else if (this->numerator->getType() == "Root"&&this->denominator->getType() == "Rational"){
		Root* newNum = dynamic_cast<Root*>(this->numerator);
		Rational* newDenom = dynamic_cast<Rational*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom);
		newCo->simplify();
		newNum->setCoefficient(newCo);
		this->numerator = newNum;
		this->denominator = new Integer();
	}
	else if (this->numerator->getType() == "Root"&&this->denominator->getType() == "Pi"){
		Root* newNum = dynamic_cast<Root*>(this->numerator);
		Pi* newDenom = dynamic_cast<Pi*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator);
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Root"&&this->denominator->getType() == "NatE"){
		Root* newNum = dynamic_cast<Root*>(this->numerator);
		NatE* newDenom = dynamic_cast<NatE*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator);
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Root"&&this->denominator->getType() == "Log"){
		Root* newNum = dynamic_cast<Root*>(this->numerator);
		Log* newDenom = dynamic_cast<Log*>(this->denominator);
		Rational* newCo = new Rational(newNum->getCoefficient(), newDenom->getCoefficient());
		newCo->simplify();
		newNum->setCoefficient(newCo->getNumerator());
		newDenom->setCoefficient(newCo->getDenominator);
		this->numerator = newNum;
		this->denominator = newDenom;
	}
	else if (this->numerator->getType() == "Root"&&this->denominator->getType() == "Expression"){
	}
	else if (this->numerator->getType() == "Expression"&&this->denominator->getType == "Integer"){
		//Distributes integer through expression; for loop should cover it.
	}
	else if (this->numerator->getType() == "Expression"&&this->denominator->getType == "Rational"){
		//distributes denominator by multiplication, does another Rational with the denominator on the bottom
	}
	else if (this->numerator->getType() == "Expression"&&this->denominator->getType == "Pi"){
		//i don't even knowwwww
	}
	else if (this->numerator->getType() == "Expression"&&this->denominator->getType == "NatE"){
		//ewwwwwwww
	}
	else if (this->numerator->getType() == "Expression"&&this->denominator->getType == "Log"){
		//Why do I hate myself?
	}
	else if (this->numerator->getType() == "Expression"&&this->denominator->getType == "Root"){
		// *vomits*
	}
	
}


void Rational::leastCommonDenom(int& n, int& d){
	for (int i = 0; i < d; i++){
		if (n%i == 0 && d%i == 0){
			n = n / i;
			d = d / i;
			leastCommonDenom(n, d);
		}
	}
}

Number* Rational::getNumerator(){
	return this->numerator;
}

Number* Rational::getDenominator(){
	return this->denominator
		;
}

void Rational::setNumerator(Number* numer){
	this->numerator = numer;
}

void Rational::setDenominator(Number* denom){
	this->denominator = denom;
}

bool Rational::operator==(Number* a){
		if (a->getType() == "Rational"){
			Rational* in = dynamic_cast<Rational*>(a);
			if (in->getNumerator() == this->numerator){
				if (in->getDenominator() == this->denominator){
					return true;
				}
				
			}
		}
		return false;
}

string Rational::toString(){
	string str;
	simplify();
	str += "(";
	str += this->numerator->toString();
	str += "/";
	str += this->denominator->toString();
	str += ")";
	return str;
}