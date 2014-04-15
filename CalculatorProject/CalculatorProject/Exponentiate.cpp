#include "Exponentiate.h"

Exponentiate::Exponentiate()
{
}

Exponentiate::~Exponentiate()
{
}

Number* Exponentiate::evaluate(Number* a, Number* b)
{

	if (a->getType() == "Integer" && b->getType() == "Integer"){

		Integer* aCast = dynamic_cast<Integer*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		int base = aCast->getValue();
		int exponent = bCast->getValue();

		Number* result = new Integer((int)pow(base, exponent));

		return result;

	} // END INTEGER ^ INTEGER
	else if (a->getType() == "Integer" && b->getType() == "Rational"){

		Integer* aCast = dynamic_cast<Integer*>(a);
		Rational* bCast = dynamic_cast<Rational*>(b);

		Number* nNumber = bCast->getDenominator();
		Number* numberExponent = bCast->getNumerator();

		Integer* exponentCast = dynamic_cast<Integer*>(numberExponent);

		if (exponentCast->getValue() < 0){

			Number* oneNumerator = new Integer(1);
			Rational* newA = new Rational(oneNumerator, a);

			int base = aCast->getValue();
			int exponent = exponentCast->getValue();

			Number* root = new Integer((int)pow(base, exponent));

			Number* rootResult = new Root(nNumber, root);
			rootResult->simplify();

			newA->setDenominator(rootResult);

			return newA;

		}
		else {

			int base = aCast->getValue();
			int exponent = exponentCast->getValue();

			Number* root = new Integer((int)pow(base, exponent));

			Number* result = new Root(nNumber, root);
			result->simplify();

			return result;

		}

	} // END INTEGER ^ RATIONAL
	else if (a->getType() == "Rational" && b->getType() == "Integer"){

		Rational* aCast = dynamic_cast<Rational*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		Number* numeratorInput = aCast->getNumerator();
		Number* denomenatorInput = aCast->getDenominator();

		Number* numerator = evaluate(numeratorInput, b);
		Number* denomenator = evaluate(denomenatorInput, b);

		Number* result = new Rational(numerator, denomenator);
		result->simplify();

		return result;

	} // END RATIONAL ^ INTEGER
	else if (a->getType() == "Rational" && b->getType() == "Rational"){
	
		Rational* aCast = dynamic_cast<Rational*>(a);
		Rational* bCast = dynamic_cast<Rational*>(b);

		Number* numerator = evaluate(aCast->getNumerator(), bCast->getNumerator());
		Number* denomenator = evaluate(aCast->getDenominator(), bCast->getDenominator());

		Number* result = new Rational(numerator, denomenator);
		result->simplify();

		return result;

	
	} // END RATIONAL ^ RATIONAL
	else if (a->getType() == "NatE" && b->getType() == "Integer"){

		NatE* aCast = dynamic_cast<NatE*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		Number* coefficientNumber = aCast->getCoefficient();

		Number* coefficient;

		if (coefficientNumber->getType() == "Integer"){

			Integer* coefficientNumberCast = dynamic_cast<Integer*>(coefficientNumber);

			coefficient = new Integer((int)pow(coefficientNumberCast->getValue(), bCast->getValue()));

		}
		else {

			coefficient = evaluate(coefficientNumber, b);

		}

		Number* result = new NatE(coefficient, b);
		result->simplify();

		return result;

	} // END NATE ^ INTEGER
	else if (a->getType() == "Pi" && b->getType() == "Integer"){

		Pi* aCast = dynamic_cast<Pi*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		Number* coefficientNumber = aCast->getCoefficient();

		Number* coefficient;

		if (coefficientNumber->getType() == "Integer"){

			Integer* coefficientNumberCast = dynamic_cast<Integer*>(coefficientNumber);

			coefficient = new Integer((int)pow(coefficientNumberCast->getValue(), bCast->getValue()));

		}
		else {

			coefficient = evaluate(coefficientNumber, b);

		}

		Number* result = new Pi(coefficient, b);
		result->simplify();

		return result;

	} // END PI ^ INTEGER
	else if (a->getType() == "Log" && b->getType() == "Integer"){

		Log* aCast = dynamic_cast<Log*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		Number* coefficientNumber = aCast->getCoefficient();

		Number* coefficient;

		if (coefficientNumber->getType() == "Integer"){

			Integer* coefficientNumberCast = dynamic_cast<Integer*>(coefficientNumber);

			coefficient = new Integer((int)pow(coefficientNumberCast->getValue(), bCast->getValue()));

		}
		else {

			coefficient = evaluate(coefficientNumber, b);

		}

		Number* result = new Log(aCast->getBase(), aCast->getOperand(), coefficient, b);
		result->simplify();

		return result;

	} // END LOG ^ INTEGER
	else if (a->getType() == "Root" && b->getType() == "Integer"){

		Root* aCast = dynamic_cast<Root*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		Number* coefficientNumber = aCast->getCoefficient();

		Number* coefficient;

		if (coefficientNumber->getType() == "Integer"){

			Integer* coefficientNumberCast = dynamic_cast<Integer*>(coefficientNumber);

			coefficient = new Integer((int)pow(coefficientNumberCast->getValue(), bCast->getValue()));

		}
		else {

			coefficient = evaluate(coefficientNumber, b);

		}

		Number* result = new Root(aCast->getOperand(), aCast->getRoot(), coefficient, b);
		result->simplify();

		return result;

	} // END ROOT ^ INTEGER
	else if (a->getType() == "NatE" && b->getType() == "Rational"){

		NatE* aCast = dynamic_cast<NatE*>(a);
		aCast->setExponent(b);
		aCast->simplify();
		return aCast;

	} // END NATE ^ RATIONAL
	else if (a->getType() == "Pi" && b->getType() == "Pi"){

		Pi* aCast = dynamic_cast<Pi*>(a);
		aCast->setExponent(b);
		aCast->simplify();
		return aCast;

	} // END PI ^ RATIONAL
	else if (a->getType() == "Log" && b->getType() == "Rational"){

		Log* aCast = dynamic_cast<Log*>(a);
		aCast->setExponent(b);
		aCast->simplify();
		return aCast;

	} // END LOG ^ RATIONAL
	else if (a->getType() == "Root" && b->getType() == "Rational"){

		Root* aCast = dynamic_cast<Root*>(a);
		aCast->setExponent(b);
		aCast->simplify();
		return aCast;

	} // END NATE ^ RATIONAL
	
}
