#include "Divide.h"


Divide::Divide()
{
}

Divide::~Divide()
{
}

Divide::evaluate(Number a, Number b)
{
    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();

  //dividing two rationals
  if(a->getType()=="Rational" && b->getType()=="Rational")
  {
      int newNumer = a->getNumerator() * b->getDenominator();
      int newDenom = a->getDenominator() * b->getNumerator();

      Number* result = new Number();
      result->setNumerator(newNumer);
      result->setDenominator(newDenom);
      result->simplify();
  }
 return result;

}
