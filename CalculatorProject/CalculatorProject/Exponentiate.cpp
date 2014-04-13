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

		Number* result = new Integer(pow(base, exponent));

		return result;

	}
	else if (a->getType == "Integer" && b->getType() == "Rational"){

		Integer* aCast = dynamic_cast<Integer*>(a);
		Rational* bCast = dynamic_cast<Rational*>(b);

		Number* nNumber = bCast->getDenominator();
		Number* numberExponent = bCast->getNumerator();

		Integer* exponentCast = dynamic_cast<Integer*>(numberExponent);

		int base = aCast->getValue();
		int exponent = exponentCast->getValue();

		Number* root = new Integer(pow(base, exponent));

		Number* result = new Root(nNumber, root);
		result->simplify();

		return result;

	}
	else if (a->getType == "Rational" && b->getType == "Integer"){

		Rational* aCast = dynamic_cast<Rational*>(a);
		Integer* bCast = dynamic_cast<Integer*>(b);

		Number* numeratorInput = aCast->getNumerator();
		Number* denomenatorInput = aCast->getDenominator();

		Number* numerator;
		Number* denomenator;

		if (numeratorInput->getType() == "Integer"){

			Integer* numeratorInputCast = dynamic_cast<Integer*>(numeratorInput);
			numerator = new Integer(pow(numeratorInputCast->getValue(), bCast->getValue()));

		}
		else if (numeratorInput->getType() == "NatE"){

			NatE* numeratorInputCast = dynamic_cast<NatE*>(numeratorInput);

			Number* coefficientNumber = numeratorInputCast->getCoefficient();
			
			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			numerator = new NatE(coefficient, b);

		}
		else if (numeratorInput->getType() == "Pi"){

			Pi* numeratorInputCast = dynamic_cast<Pi*>(numeratorInput);

			Number* coefficientNumber = numeratorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			numerator = new Pi(coefficient, b);

		}
		else if (numeratorInput->getType() == "Log"){

			Log* numeratorInputCast = dynamic_cast<Log*>(numeratorInput);

			Number* coefficientNumber = numeratorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			numerator = new Log(numeratorInputCast->getBase(), numeratorInputCast->getOperand(), coefficient, bCast);

		}
		else if (numeratorInput->getType() == "Root"){

			Root* numeratorInputCast = dynamic_cast<Root*>(numeratorInput);

			Number* coefficientNumber = numeratorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			numerator = new Root(numeratorInputCast->getOperand(), numeratorInputCast->getRoot(), coefficient, b);

		}

		if (denomenatorInput->getType() == "Integer"){

			Integer* denomenatorInputCast = dynamic_cast<Integer*>(denomenatorInput);
			denomenator = new Integer(pow(denomenatorInputCast->getValue(), bCast->getValue()));

		}
		else if (denomenatorInput->getType() == "NatE"){

			NatE* denomenatorInputCast = dynamic_cast<NatE*>(denomenatorInput);

			Number* coefficientNumber = denomenatorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			denomenator = new NatE(coefficient, b);

		}
		else if (denomenatorInput->getType() == "Pi"){

			Pi* denomenatorInputCast = dynamic_cast<Pi*>(denomenatorInput);

			Number* coefficientNumber = denomenatorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			denomenator = new Pi(coefficient, b);

		}
		else if (denomenatorInput->getType() == "Log"){

			Log* denomenatorInputCast = dynamic_cast<Log*>(denomenatorInput);

			Number* coefficientNumber = denomenatorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			denomenator = new Log(denomenatorInputCast->getBase(), denomenatorInputCast->getOperand(), coefficient, bCast);

		}
		else if (denomenatorInput->getType() == "Root"){

			Root* denomenatorInputCast = dynamic_cast<Root*>(denomenatorInput);

			Number* coefficientNumber = denomenatorInputCast->getCoefficient();

			Number* coefficient;

			if (coefficientNumber->getType() == "Integer"){

				Integer* coefficientNumber = dynamic_cast<Integer*>(coefficientNumber);

				coefficient = new Integer(pow(coefficientNumber->getValue(), bCast->getValue()));

			}
			else {

				coefficient = evaluate(coefficientNumber, b);

			}

			denomenator = new Root(denomenatorInputCast->getOperand(), denomenatorInputCast->getRoot(), coefficient, b);

		}

	}

}
