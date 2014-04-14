#include "Divide.h"

Divide::Divide()
{
}

Divide::~Divide()
{
}

Number* Divide::evaluate(Number* a, Number* b)
{
    Number* result = new Rational(a, b);
    result->simplify();
    return result;
}
