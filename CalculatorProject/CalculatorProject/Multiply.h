#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <iostream>
using namespace std;
#include "Operations.h"

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
