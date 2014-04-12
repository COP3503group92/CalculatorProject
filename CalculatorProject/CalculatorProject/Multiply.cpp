#include "Multiply.h"


Multiply::Multiply()
{
}

Multiply::~Multiply()
{
}



static Number Multiply::evaluate(Number* a, Number* b)
{
    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();
    Operator* op = new Operator(cl);

/0) both integers
/1)both rationals
/2)first is rational, second is specialCase
/3)first is specialCase, second is rational
/4)both are specialCases:
/  -->both same typede
/  -->
  if(a->getType()=="Rational" && b->getType()=="Rational")
  {
      int newNumer = a->getNumerator() * b->getNumerator();
      int newDenom = a->getDenominator() * b->getDenominator();

      Number* product = new Number();
      product->setNumerator(newNumer);
      product->setDenominator(newDenom);
      product->simplify();
  }
    //3 * pi
  if(a->getType()=="Rational" && b->getType()=="Pi")
  {
      ostringstream os;
            os << a->getNumerator() << b->getNumerator();
            string newNumer = os.str();

            Number* sum = new Number();
            sum->setNumerator(os.str());

  }
  return product;



}
