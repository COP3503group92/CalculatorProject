#include "Subtract.h"


Subtract::Subtract()
{
}

Subtract::~Subtract()
{
}

static Number Subtract::evaluate(Number* a, Number* b)
{
//0) if both numbers are "integer"
//1) If both numbers are "Rational"
/2) If the first number is "special", second is "rational"
/3) if the first number is "rational", second is "specialcase"
/4) if both numbers are "SpecialCase"
/   -->if both Numbers are the same special
/   -->if both are different specials
/***************************************************************/

    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();
    Operator* op = new Operator(cl);

        //Case #0
        if(a->getType()=="Integer" && b->getType()=="Integer")
        {
            int diff = a->getValue() - b->getValue();
            Integer* i = new Integer(diff);
            return i;
        }
        //Case #1
        //ie: (3/1) - (3/1)
        if(numTypeA=="Rational" && denomTypeA=="Rational" && numTypeB=="Rational" && denomTypeB=="Rational")
            {
            int subNumerA = b->getDenominator() * a->getNumerator();
            int subDenomA = b->getDenominator() * a->getDenominator();
            int subNumerB = a->getDenominator() * b->getNumerator();
            int subDenomB = a->getDenominator() * b->getDenominator();

            int newNumer = subNumerA - subNumerB;

            Number *sum = new Number();
            sum->setNumerator(newNumer);
            sum->setDenominator(subDenomA);
            sum->simplify();
            }
        return sum;
}
