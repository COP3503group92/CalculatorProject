#include "Exponentiate.h"

Exponentiate::Exponentiate()
{
}

Exponentiate::~Exponentiate()
{
}

static Number Exponentiate::evaluate(Number* a, Number* b)
{
    string numTypeA = a->getNumerator()->getType();
    string denomTypeA = a->getDenomerator()->getType();
    string numTypeB = b->getNumerator()->getType();
    string denomTypeB = b->getNumerator()->getType();
    Operator* op = new Operator(cl);

}
