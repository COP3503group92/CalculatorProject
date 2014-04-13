#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Includes.h"

class Multiply : public Operations
{
    public:
        Multiply();
		Multiply(Number* a, Number* b);
        virtual ~Multiply();
        Number* evaluate();
    protected:
    private:
        string cl = "*";
		Number* a;
		Number* b;
};

#endif // MULTIPLY_H
