#include "Multiply.h"


Multiply::Multiply()
{
}

Multiply::~Multiply()
{
}



Multiply::evaluate(Number a, Number b)
{
    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();

//Multiplying two rational numbers
//distribution?
  if(a->getType()=="Rational" && b->getType()=="Rational")
  {
      int newNumer = a->getNumerator() * b->getNumerator();
      int newDenom = a->getDenominator() * b->getDenominator();

      Number* product = new Number();
      product->setNumerator(newNumer);
      product->setDenominator(newDenom);
      product->simplify();
  }
  return product;

}
