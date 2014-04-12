#include "Add.h"
#include "Include.h"

Add::Add()
{
}

Add::~Add()
{
}

static Number Add::evaluate(Number* a, Number* b)
{
/0) All cases where "a" is an "Integer"
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
/***************************************************************/

    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();
    Operator* op = new Operator(cl);

    //Case #0
    //if Number "a" == "Integer"
    if(a->getType=="Integer")
    {
        if(b->getType=="Integer")
        {
            int sum = a->getValue() + b->getValue();
            Integer* i = new Integer(sum);
            return i;
        }
        if(b->getType=="Rational")
        {
            Rational* i = new Rational(a);
            i->simplify();
            evaluate(i, b);
            return 0;
        }
        if(b->getType=="NatE")
        {
            Expression* ee = new Expression();
            Expression.add(a, b, op);
            return ee;
        }
        if(b->getType=="Pi")
        {
            Expression* ee = new Expression();
            Expression.add(a, b, op);
            return ee;
        }
        if(b->getType=="Log")
        {
            Expression* ee = new Expression();
            Expression.add(a, b, op);
            return ee;
        }
        if(b->getType=="Root")
        {
            Expression* ee = new Expression();
            Expression.add(a, b, op);
            return ee;
        }
        if(b->getType=="Expression")
        {
            Expression* ee = new Expression();
            Expression.add(a, b, op);
            return ee;
        }
     return 0;
    }

    //Case #1
    //Number "a" == Rational
        //ie: (3/1) + (3/1)
    if(a->getType()=="Rational" && b->getType()=="Rational")
    {

        if(numTypeA=="Integer" && denomTypeA=="Integer" && numTypeB=="Integer" && denomTypeB=="Integer")
            {
            int subNumerA = b->getDenominator() * a->getNumerator();
            int subDenomA = a->getDenominator() * b->getDenominator();
            int subNumerB = a->getDenominator() * b->getNumerator();

            int newNumer = subNumerA + subNumerB;

            Number *sum = new Number();
            sum->setNumerator(newNumer);
            sum->setDenominator(subDenomA);
            sum->simplify();
            }
        //ie: (3/1) + (1/pi)
       /* if(numTypeA=="Rational" && denomTypeA=="Rational" && numTypeB=="Rational" && denomTypeB=="SpecialCase")
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
            */
      //(2/1 + (Log)(e)(pi))
      if(a->getType()=="Rational" && b->getType()=="NatE")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Rational" && b->getType()=="Pi")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Rational" && b->getType()=="Log")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Rational" && b->getType()=="Root")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Rational" && b->getType()=="Expression")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
     return 0;
    }

  //Case #2
  //e(pi)(log)(rt)(3+e) + 2
      if(a->getType()=="NatE" && b->getType()=="Rational")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Pi" && b->getType()=="Rational")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Log" && b->getType()=="Rational")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Root" && b->getType()=="Rational")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }
      if(a->getType()=="Expression" && b->getType()=="Rational")
      {
        Expression* ee = new Expression();
        Expression.add(a, b, op);
        return ee;
      }


  //Case #4
  //both "SpecialCase"

      //both the same kind of "SpecialCase"
      if(a->getType()=="pi" && b->getType()=="pi")
      {

      }
      //both different "SpecialCases"
      if(a->getType()=="Rational" && b->getType()=="")

    return sum;


}
