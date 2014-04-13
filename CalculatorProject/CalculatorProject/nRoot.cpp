#include "nRoot.h"

nRoot::nRoot()
{
}

nRoot::~nRoot()
{
}

Number* nRoot::evaluate(Number* a, Number* b)
{
    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();
    Operator* op = new Operator(cl);

}
