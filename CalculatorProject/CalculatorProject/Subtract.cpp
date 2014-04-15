#include "Subtract.h"


Subtract::Subtract()
{
}

Subtract::~Subtract()
{
}

Number* Subtract::evaluate(Number* a, Number* b)
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

    //Case #0
    //if Number "a" == "Integer"
    if(a->getType()=="Integer")
    {
        if(b->getType()=="Integer")
        {
            Integer* first = dynamic_cast<Integer*>(a);
            Integer* second = dynamic_cast<Integer*>(b);
            int sum = first->getValue() - second->getValue();
            Integer* i = new Integer(sum);
            return i;
        }
        else if(b->getType()=="Rational")
        {
            Rational* i = dynamic_cast<Rational*>(a);
            i->simplify();
            evaluate(i, b);
            return 0;
        }
        else if(b->getType()=="NatE")
        {
            Operator* op = new Operator(cl);
            Expression* ee = new Expression();
            ee->add(a, b, op);
            return ee;
        }
        else if(b->getType()=="Pi")
        {
            Operator* op = new Operator(cl);
            Expression* ee = new Expression();
            ee->add(a, b, op);
            return ee;
        }
        else if(b->getType()=="Log")
        {
            Operator* op = new Operator(cl);
            Expression* ee = new Expression();
            ee->add(a, b, op);
            return ee;
        }
        else if(b->getType()=="Root")
        {
            Operator* op = new Operator(cl);
            Expression* ee = new Expression();
            ee->add(a, b, op);
            return ee;
        }
        else if(b->getType()=="Expression")
        {
            Operator* op = new Operator(cl);
            Expression* ee = new Expression();
            ee->add(a, b, op);
            return ee;
        }
     return 0;
    }

    //Case #1
    //Number "a" == Rational
        //ie: (3/1) + (3/1)
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

            Integer* subNumerA = new Integer(secD->getValue() * firN->getValue());
            Integer* subDenomA = new Integer(firD->getValue() * secD->getValue());
            Integer* subNumerB = new Integer(firD->getValue() * secN->getValue());

            Subtract* p = new Subtract();
            Integer* newNumer = new Integer();
			Integer* se = dynamic_cast<Integer*>(p->evaluate(subNumerA, subNumerB));
			newNumer = se;

            Rational* diff = new Rational(newNumer, subDenomA);
            diff->setNumerator(newNumer);
            diff->setDenominator(subDenomA);
            diff->simplify();
            return diff;
        }
       //ie: (3/1) + (1/e)
       else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Integer"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="NatE")
       {
        Operator* op = new Operator(cl);
        first->simplify();
        second->simplify();
        Expression* ee = new Expression();
        ee->add(first, second, op);
        return ee;
       }
       //ie: (3/1) + (1/pi)
       else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Integer"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Pi")
       {
        Operator* op = new Operator(cl);
        first->simplify();
        second->simplify();
        Expression* ee = new Expression();
        ee->add(first, second, op);
        return ee;
       }
       //ie: (3/1) + (1/Log)
       else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Integer"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Log")
       {
        Operator* op = new Operator(cl);
        first->simplify();
        second->simplify();
        Expression* ee = new Expression();
        ee->add(first, second, op);
        return ee;
       }
       //ie: (3/1) + (1/root)
       else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Integer"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Root")
       {
        Operator* op = new Operator(cl);
        first->simplify();
        second->simplify();
        Expression* ee = new Expression();
        ee->add(first, second, op);
        return ee;
       }
       //ie: (3/1) + (1/Expression)
       else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Integer"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Expression")
       {
        Operator* op = new Operator(cl);
        first->simplify();
        second->simplify();
        Expression* ee = new Expression();
        ee->add(first, second, op);
        return ee;
       }


      //ie: (1/e) + (3/1)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="NatE"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Integer")
            {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
            }
        //ie: (1/pi + (3/1)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Pi"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Integer")
            {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
            }
        //ie: (1/log) + (3/1)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Log"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Integer")
            {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
            }
        //ie: (1/root) + (3/1)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Root"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Integer")
            {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
            }
        //ie: (1/Expression) + (3/1)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Expression"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Integer")
            {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
            }

        //if Denominators are same special
        //-------------------------
        //ie: (1/e) + (1/e)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="NatE"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="NatE")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/pi) + (1/pi)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Pi"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Pi")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/log) + (1/log)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Log"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Log")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/root) + (1/root)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Root"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Root")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/expression) + (1/expression)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Expression"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Expression")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }


        //if Denominators are different specials
        //-------------------------------
        //ie:(1/e) + (1/pi)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="NatE"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Pi")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/e) + (1/ Log)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="NatE"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Log")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie:(1/e) + (1/root)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="NatE"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Root")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/e) + (1/expression)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="NatE"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Expression")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/pi) + (1/e)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Pi"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="NatE")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/pi) + (1/log)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Pi"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Log")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/pi) + (1/root)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Pi"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Root")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/pi) + (1/expression)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Pi"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Expression")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/log) + (1/e)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Log"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="NatE")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/log) + (1/pi)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Log"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Pi")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/log) + (1/root)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Log"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Root")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/log) + (1/expression)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Log"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Expression")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/root) + (1/e)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Root"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="NatE")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/root) + (1/pi)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Root"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Pi")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/root) + (1/log)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Root"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Log")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/root) + (1/expression)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Root"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Expression")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/express) + (1/e)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Expression"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="NatE")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/express) + (1/pi)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Expression"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Pi")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/express) + (1/log)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Expression"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Log")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }
        //ie: (1/express) + (1/root)
        else if(first->getNumerator()->getType()=="Integer" && first->getDenominator()->getType()=="Expression"
            && second->getNumerator()->getType()=="Integer" && second->getDenominator()->getType()=="Root")
               {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* ee = new Expression();
                ee->add(first, second, op);
                return ee;
               }

      return 0;
    }

      //(2/1 + SpecialCase)
      else if(a->getType()=="Rational" && b->getType()=="NatE")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Rational" && b->getType()=="Pi")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Rational" && b->getType()=="Log")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Rational" && b->getType()=="Root")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Rational" && b->getType()=="Expression")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }


  //Case #2
  //(SpecialCase) + 2
	  else if (a->getType() == "NatE" && b->getType() == "Integer")
	  {
		  Operator* op = new Operator(cl);
		  a->simplify();
		  b->simplify();
		  Expression* ee = new Expression();
		  ee->add(a, b, op);
		  return ee;
	  }
	  else if (a->getType() == "Pi" && b->getType() == "Integer")
	  {
		  Operator* op = new Operator(cl);
		  a->simplify();
		  b->simplify();
		  Expression* ee = new Expression();
		  ee->add(a, b, op);
		  return ee;
	  }
	  else if (a->getType() == "Log" && b->getType() == "Integer")
	  {
		  Operator* op = new Operator(cl);
		  a->simplify();
		  b->simplify();
		  Expression* ee = new Expression();
		  ee->add(a, b, op);
		  return ee;
	  }
	  else if (a->getType() == "Root" && b->getType() == "Integer")
	  {
		  Operator* op = new Operator(cl);
		  a->simplify();
		  b->simplify();
		  Expression* ee = new Expression();
		  ee->add(a, b, op);
		  return ee;
	  }
	  else if (a->getType() == "Expression" && b->getType() == "Integer")
	  {
		  Operator* op = new Operator(cl);
		  a->simplify();
		  b->simplify();
		  Expression* ee = new Expression();
		  ee->add(a, b, op);
		  return ee;
	  }
      else if(a->getType()=="NatE" && b->getType()=="Rational")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Pi" && b->getType()=="Rational")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Log" && b->getType()=="Rational")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Root" && b->getType()=="Rational")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }
      else if(a->getType()=="Expression" && b->getType()=="Rational")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* ee = new Expression();
        ee->add(a, b, op);
        return ee;
      }


  //Case #4
  //both "SpecialCase"

      //both the same kind of "SpecialCase"
      //-----------------------------------
      //ie: e + e
      else if(a->getType()=="NatE" && b->getType()=="NatE")
      {
        NatE* first = dynamic_cast<NatE*>(a);
        NatE* second = dynamic_cast<NatE*>(b);
        Subtract* p = new Subtract();
        NatE* e = new NatE(p->evaluate(first->getCoefficient(), second->getCoefficient()));
        return e;
      }
      //ie: pi + pi
      else if(a->getType()=="Pi" && b->getType()=="Pi")
      {
        Pi* first = dynamic_cast<Pi*>(a);
        Pi* second = dynamic_cast<Pi*>(b);
        Subtract* p = new Subtract();
        Pi* e = new Pi(p->evaluate(first->getCoefficient(), second->getCoefficient()));
        return e;
      }
      //ie: log + log

      else if(a->getType()=="Log" && b->getType()=="Log")
      {
        Log* first = dynamic_cast<Log*>(a);
        Log* second = dynamic_cast<Log*>(b);
          if(first->getBase()==second->getBase() && first->getOperand()==second->getOperand())
          {
            Subtract* p = new Subtract();
			first->setCoefficient(p->evaluate(first->getCoefficient(), second->getCoefficient()));
			return first;
          }
          else
            {
                Operator* op = new Operator(cl);
                first->simplify();
                second->simplify();
                Expression* e = new Expression();
                e->add(first, second, op);
				return e;
            }
        
      }
      //ie: root + root
      else if(a->getType()=="Root" && b->getType()=="Root")
      {
        Root* first = dynamic_cast<Root*>(a);
        Root* second = dynamic_cast<Root*>(b);
          if(first->getRoot()==second->getRoot() && first->getOperand()==second->getOperand())
          {
            Subtract* p = new Subtract();
            first->setCoefficient(p->evaluate(first->getCoefficient(), second->getCoefficient()));
			return first;
          }
          else
          {
            Operator* op = new Operator(cl);
            first->simplify();
            second->simplify();
            Expression* e = new Expression();
            e->add(first, second, op);
			return e;
          }
        
      }
      //ie: expression + expression
      else if(a->getType()=="Expression" && b->getType()=="Expression")
      {
        return 0;
      }


      //both different "SpecialCases"
      //ie: e + pi
      else if(a->getType()=="NatE" && b->getType()=="Pi")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: e + log
      else if(a->getType()=="NatE" && b->getType()=="Log")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: e + Root
      else if(a->getType()=="NatE" && b->getType()=="Root")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: e + Expression
      else if(a->getType()=="NatE" && b->getType()=="Expression")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: pi + e
      else if(a->getType()=="Pi" && b->getType()=="NatE")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: pi + log
      else if(a->getType()=="Pi" && b->getType()=="Log")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: pi + root
      else if(a->getType()=="Pi" && b->getType()=="Root")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: pi + expression
      else if(a->getType()=="Pi" && b->getType()=="Expression")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: log + e
      else if(a->getType()=="Log" && b->getType()=="NatE")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: log + pi
      else if(a->getType()=="Log" && b->getType()=="Pi")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: log + root
      else if(a->getType()=="Log" && b->getType()=="Root")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: log + express
      else if(a->getType()=="Log" && b->getType()=="Expression")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: root + e
      else if(a->getType()=="Root" && b->getType()=="NatE")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: root + pi
      else if(a->getType()=="Root" && b->getType()=="Pi")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: root + log
      else if(a->getType()=="Root" && b->getType()=="Log")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }
      //ie: root + expression
      else if(a->getType()=="Root" && b->getType()=="Expression")
      {
        Operator* op = new Operator(cl);
        a->simplify();
        b->simplify();
        Expression* e = new Expression();
        e->add(a, b, op);
        return e;
      }

 return 0;
}
