#include "Multiply.h"

Multiply::Multiply()
{
}

Multiply::~Multiply()
{
}



Number* Multiply::evaluate(Number* a, Number* b)
{
/*0) All cases where "a" is an "Integer"
//    -->if both numbers are "Integer"
//    -->first int, second rational
//    -->first int, second Special(separate conditions for each special)
/1) All cases where "a" is a "Rational"
    -->If both numbers are "Rational"
    -->first rational, second int
    -->first rational, second Special(separate if statements for each type)
/2) All cases where "a" is a "SpecialCase"
    -->if both numbers are "SpecialCase"
    -->if first special, second "Integer"
    -->if first Special, second "Rational"
    -->if both Numbers are the same special(list all specials)
    -->if both are different specials
        -->if first NatE, second(Pi, Log, Root, Expression)
        -->if first Pi, second (NatE, Log, Root, Expression)
        -->etc...
*/
//***************************************************************/

    if(a->getType()=="Integer")
    {
        if(b->getType()=="Integer")
        {
            Integer* first = dynamic_cast<Integer*>(a);
            Integer* second = dynamic_cast<Integer*>(b);
            int pro = first->getValue() * second->getValue();
            Integer* i = new Integer(pro);
            return i;
        }
        else if(b->getType()=="Rational")
        {
            Rational* i = dynamic_cast<Rational*>(a);
            i->simplify();
            evaluate(i, b);
            return 0;
        }
        //3*e
        else if(b->getType()=="NatE")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            NatE* e = dynamic_cast<NatE*>(b);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
            return e;
        }
        else if(b->getType()=="Pi")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Pi* e = dynamic_cast<Pi*>(b);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
            return e;
        }
        else if(b->getType()=="Log")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Log* e = dynamic_cast<Log*>(b);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
            return e;
        }
        else if(b->getType()=="Root")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Root* e = dynamic_cast<Root*>(b);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
            return e;
        }
        else if(b->getType()=="Expression")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Expression* e = dynamic_cast<Expression*>(b);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
            return e;
        }
      return 0;
    }

    else if(a->getType()=="Rational" && b->getType()=="Rational")
    {
        Rational* first = dynamic_cast<Rational*>(a);
        Rational* second = dynamic_cast<Rational*>(b);


        if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Integer"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Integer")
        {
            Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
            Integer* firD = dynamic_cast<Integer*>(first->getDenominator());
            Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
            Integer* secD = dynamic_cast<Integer*>(second->getDenominator());

            Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
            Integer* subDenom = new Integer(firD->getValue() * secD->getValue());

            Rational* pro = new Rational(subNumer, subDenom);
            pro->setNumerator(subNumer);
            pro->setDenominator(subDenom);
            pro->simplify();
            return pro;
        }
		//if both denominators are same "specialCase"
		//-------------------------------------------
		
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "NatE"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "NatE")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			NatE* firD = dynamic_cast<NatE*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			NatE* secD = dynamic_cast<NatE*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());

			Multiply* mi = new Multiply();
			Number* newCo = mi->evaluate(firD->getCoefficient(), secD->getCoefficient());
			Add* ad = new Add();
			Number* newEx = ad->evaluate(firD->getExponent(), secD->getExponent());
			NatE* e = new NatE(newCo, newEx);
			
			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(e);
			pro->simplify();
			return pro;
			
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Pi"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Pi")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Pi* firD = dynamic_cast<Pi*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Pi* secD = dynamic_cast<Pi*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());

			Multiply* mi = new Multiply();
			Number* newCo = mi->evaluate(firD->getCoefficient(), secD->getCoefficient());
			Add* ad = new Add();
			Number* newEx = ad->evaluate(firD->getExponent(), secD->getExponent());
			Pi* e = new Pi(newCo, newEx);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(e);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Log"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Log")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Log* firD = dynamic_cast<Log*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Log* secD = dynamic_cast<Log*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());

			Multiply* mi = new Multiply();
			Number* newCo = mi->evaluate(firD->getCoefficient(), secD->getCoefficient());
			Add* ad = new Add();
			Number* newEx = ad->evaluate(firD->getExponent(), secD->getExponent());
			Log* e = new Log(newCo, newEx);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(e);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Root")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Root* secD = dynamic_cast<Root*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());

			Multiply* mi = new Multiply();
			Number* newCo = mi->evaluate(firD->getCoefficient(), secD->getCoefficient());
			Add* ad = new Add();
			Number* newEx = ad->evaluate(firD->getExponent(), secD->getExponent());
			Root* e = new Root(newCo, newEx);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(e);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Expression"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Expression")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Expression* firD = dynamic_cast<Expression*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Expression* secD = dynamic_cast<Expression*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());

			Multiply* mi = new Multiply();
			Number* newCo = mi->evaluate(firD->getCoefficient(), secD->getCoefficient());
			Number* newEx = mi->evaluate(firD->getExponent(), secD->getExponent());
			Expression* e = new Expression();
			e->add(firD, secD, new Operator(cl));
			e->setCoefficient(newCo);
			e->setExponent(newEx);
			
			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(e);
			pro->simplify();
			return pro;

			
			
		}
		
		//denominators have different specialCases...
		//...........................................
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "NatE"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Pi")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			NatE* firD = dynamic_cast<NatE*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Pi* secD = dynamic_cast<Pi*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "NatE"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Log")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			NatE* firD = dynamic_cast<NatE*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Log* secD = dynamic_cast<Log*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "NatE"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Root")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			NatE* firD = dynamic_cast<NatE*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Root* secD = dynamic_cast<Root*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "NatE"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Expression")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			NatE* firD = dynamic_cast<NatE*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Expression* secD = dynamic_cast<Expression*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Pi"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "NatE")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Pi* firD = dynamic_cast<Pi*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			NatE* secD = dynamic_cast<NatE*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Pi"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Log")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Pi* firD = dynamic_cast<Pi*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Log* secD = dynamic_cast<Log*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Pi"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Root")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Pi* firD = dynamic_cast<Pi*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Root* secD = dynamic_cast<Root*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Pi"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Expression")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Pi* firD = dynamic_cast<Pi*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Expression* secD = dynamic_cast<Expression*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Log"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "NatE")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Log* firD = dynamic_cast<Log*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			NatE* secD = dynamic_cast<NatE*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Log"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Pi")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Log* firD = dynamic_cast<Log*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Pi* secD = dynamic_cast<Pi*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Log"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Root")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Log* firD = dynamic_cast<Log*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Root* secD = dynamic_cast<Root*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Log"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Expression")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Log* firD = dynamic_cast<Log*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Expression* secD = dynamic_cast<Expression*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "NatE")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			NatE* secD = dynamic_cast<NatE*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Pi")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Pi* secD = dynamic_cast<Pi*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Log")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Log* secD = dynamic_cast<Log*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Log")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Log* secD = dynamic_cast<Log*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Expression")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Expression* secD = dynamic_cast<Expression*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "NatE")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			NatE* secD = dynamic_cast<NatE*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Pi")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Pi* secD = dynamic_cast<Pi*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		else if (first->getNumerator()->getType() == "Integer" && first->getDenominator()->getType() == "Root"
			&& second->getNumerator()->getType() == "Integer" && second->getDenominator()->getType() == "Log")
		{
			Integer* firN = dynamic_cast<Integer*>(first->getNumerator());
			Root* firD = dynamic_cast<Root*>(first->getDenominator());
			Integer* secN = dynamic_cast<Integer*>(second->getNumerator());
			Log* secD = dynamic_cast<Log*>(second->getDenominator());

			Integer* subNumer = new Integer(firN->getValue() * secN->getValue());
			Multiply* mi = new Multiply();
			Number* nu = mi->evaluate(firD, secD);

			Rational* pro = new Rational();
			pro->setNumerator(subNumer);
			pro->setDenominator(nu);
			pro->simplify();
			return pro;
		}
		
        

        return 0;
    }

	

	//Special Case times SpecialCase (same kind of special)
	else if (a->getType() == "NatE" && b->getType() == "NatE")
	{
		NatE* fir = dynamic_cast<NatE*>(a);
		NatE* sec = dynamic_cast<NatE*>(b);

		Multiply* mi = new Multiply();
		Number* newCo = mi->evaluate(fir->getCoefficient(), sec->getCoefficient());
		Number* newEx = mi->evaluate(fir->getExponent(), sec->getExponent());
		NatE* e = new NatE(newCo, newEx);
		return e;
	}
	else if (a->getType() == "Pi" && b->getType() == "Pi")
	{
		Pi* fir = dynamic_cast<Pi*>(a);
		Pi* sec = dynamic_cast<Pi*>(b);

		Multiply* mi = new Multiply();
		Number* newCo = mi->evaluate(fir->getCoefficient(), sec->getCoefficient());
		Number* newEx = mi->evaluate(fir->getExponent(), sec->getExponent());
		Pi* e = new Pi(newCo, newEx);
		return e;
	}
	else if (a->getType() == "Log" && b->getType() == "Log")
	{
		Log* fir = dynamic_cast<Log*>(a);
		Log* sec = dynamic_cast<Log*>(b);

		Multiply* mi = new Multiply();
		Number* newCo = mi->evaluate(fir->getCoefficient(), sec->getCoefficient());
		Number* newEx = mi->evaluate(fir->getExponent(), sec->getExponent());
		Log* e = new Log(newCo, newEx);
		return e;
	}
	else if (a->getType() == "Root" && b->getType() == "Root")
	{
		Root* fir = dynamic_cast<Root*>(a);
		Root* sec = dynamic_cast<Root*>(b);

		Multiply* mi = new Multiply();
		Number* newCo = mi->evaluate(fir->getCoefficient(), sec->getCoefficient());
		Number* newEx = mi->evaluate(fir->getExponent(), sec->getExponent());
		Root* e = new Root(newCo, newEx);
		return e;
	}
	else if (a->getType() == "Expression" && b->getType() == "Expression")
	{
		Expression* fir = dynamic_cast<Expression*>(a);
		Expression* sec = dynamic_cast<Expression*>(b);

		Multiply* mi = new Multiply();
		Number* newCo = mi->evaluate(fir->getCoefficient(), sec->getCoefficient());
		Number* newEx = mi->evaluate(fir->getExponent(), sec->getExponent());
		Expression* e = new Expression();
		e->add(fir, sec, new Operator(cl));
		e->setCoefficient(newCo);
		e->setExponent(newEx);
		return e;
	}
	
		
		else if (b->getType() == "Rational")
		{
			Rational* i = dynamic_cast<Rational*>(a);
			i->simplify();
			evaluate(i, b);
			return 0;
		}
		//3*e
		else if (a->getType() == "NatE" && b->getType()=="Integer")
		{
			Integer* r = dynamic_cast<Integer*>(b);
			NatE* e = dynamic_cast<NatE*>(a);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
			return e;
		}
		else if (a->getType() == "Pi" && b->getType()=="Integer")
		{
			Integer* r = dynamic_cast<Integer*>(b);
			Pi* e = dynamic_cast<Pi*>(a);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
			return e;
		}
		else if (a->getType() == "Log" && b->getType()=="Integer")
		{
			Integer* r = dynamic_cast<Integer*>(b);
			Log* e = dynamic_cast<Log*>(a);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
			return e;
		}
		else if (a->getType() == "Root" && b->getType()=="Integer")
		{
			Integer* r = dynamic_cast<Integer*>(b);
			Root* e = dynamic_cast<Root*>(a);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
			return e;
		}
		else if (a->getType() == "Expression" && b->getType()=="Integer")
		{
			Integer* r = dynamic_cast<Integer*>(b);
			Expression* e = dynamic_cast<Expression*>(a);
			e->setCoefficient(evaluate(r, e->getCoefficient()));
			return e;
		}
		
//Rational times everything else
	//-------------------------------
    else 
    {
		Number* mo = evaluate(a, b->getCoefficient());
		mo->simplify();
		b->setCoefficient(mo);
        return b;
    }





}
