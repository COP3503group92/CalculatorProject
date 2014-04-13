#include "Multiply.h"
#include "Includes.h"

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
            e->setCoefficient(evaluate(r, e->getCoefficient()))
            return e;
        }
        else if(b->getType()=="Pi")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Pi* e = dynamic_cast<Pi*>(b);
            e->setCoefficient(evaluate(r, e->getCoefficient()))
            return e;
        }
        else if(b->getType()=="Log")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Log* e = dynamic_cast<Log*>(b);
            e->setCoefficient(evaluate(r, e->getCoefficient()))
            return e;
        }
        else if(b->getType()=="Root")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Root* e = dynamic_cast<Root*>(b);
            e->setCoefficient(evaluate(r, e->getCoefficient()))
            return e;
        }
        else if(b->getType()=="Expression")
        {
            Integer* r = dynamic_cast<Integer*>(a);
            Expression* e = dynamic_cast<Expression*>(b);
            e->setCoefficient(evaluate(r, e->getCoefficient()))
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
    }



}
