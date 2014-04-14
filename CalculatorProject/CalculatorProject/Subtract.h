#pragma once

#include "Operations.h"
#include "Integer.h"
#include "Rational.h"
#include "SpecialCase.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

class Subtract : public Operations
{
    public:
        Subtract();
        virtual ~Subtract();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "-";
};
