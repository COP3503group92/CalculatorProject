#include "Addition.h"


Addition::Addition()
{
}

Addition::~Addition()
{
}

Addition::evaluate(Number* a, Number* b)
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
        //ie: (3/1) + (3/1)
        if(numTypeA=="Rational" && denomTypeA=="Rational" && numTypeB=="Rational" && denomTypeB=="Rational")
            {
            int subNumerA = b->getDenominator() * a->getNumerator();
            int subDenomA = b->getDenominator() * a->getDenominator();
            int subNumerB = a->getDenominator() * b->getNumerator();
            int subDenomB = a->getDenominator() * b->getDenominator();

            int newNumer = subNumerA + subNumerB;

            Number *sum = new Number();
            sum->setNumerator(newNumer);
            sum->setDenominator(subDenomA);
            sum->simplify();
            }
        //ie: (3/1) + (1/pi)
        if(numTypeA=="Rational" && denomTypeA=="Rational" && numTypeB=="Rational" && denomTypeB=="SpecialCase")
            {
            ostringstream os;
            os << a->getDenominator() * b->getNumerator() << " + " << a->getNumerator() << b->getDenominator();
            string newNumer = os.str();

            ostringstream s;
            s << a->getDenominator() << b->getDenominator();
            string newDenom = s.str();

            Number* sum = new Number();
            sum->setNumerator(os.str());
            sum->setDenominator(s.str());
            sum->simplify();
            }
        //ie: (1/pi) + (3/1)
        if(numTypeA=="Rational" && denomTypeA=="SpecialCase" && numTypeB=="Rational" && denomTypeB=="Rational")
            {
            ostringstream os;
            os << b->getDenominator() * a->getNumerator() << " + " << b->getNumerator() << a->getDenominator();
            string newNumer = os.str();

            ostringstream s;
            s << b->getDenominator() << a->getDenominator();
            string newDenom = s.str();

            Number* sum = new Number();
            sum->setNumerator(os.str());
            sum->setDenominator(s.str());
            sum->simplify();
            }
        //ie: (1/pi) + (1/pi)
        if(numTypeA=="Rational" && denomTypeA=="SpecialCase" && numTypeB=="Rational" && denomTypeB=="SpecialCase")
            {
                if(denominators both pi put 2 pi, etc,)
                if(denominators different)
            ostringstream os;
            os << a->getNumerator() << b->getDenominator() << " + " << b->getNumerator() << a->getDenominator();
            string newNumer = os.str();

            ostringstream s;
            s << a->getDenominator() << b->getDenominator();
            string newDenom = s.str();

            Number* sum = new Number();
            sum->setNumerator(os.str());
            sum->setDenominator(s.str());
            sum->simplify();
            }

    return sum;
  }

  //Case #2
  if(a->getType()=="SpecialCase" && b->getType()=="Rational")
  {


    return sum;
  }

  //Case #3
  if(a->getType()=="Rational" && b->getType()=="SpecialCase")
  {


    return sum;
  }

  //Case #4
  if(a->getType()=="SpecialCase" && b->getType()=="SpecialCase")
  {


    return sum;
  }

}
