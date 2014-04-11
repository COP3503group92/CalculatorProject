#include "Subtract.h"


Subtract::Subtract()
{
}

Subtract::~Subtract()
{
}

Subtract::evaluate(Number a, Number b)
{
//1) If both numbers are "Rational"
/2) If the first number is "special", second is "rational"
/3) if the first number is "rational", second is "specialcase"
/4) if both numbers are "SpecialCase"
/***************************************************************/

    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();
  if(a->getType()=="Rational" && b->getType()=="Rational")
  {
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
