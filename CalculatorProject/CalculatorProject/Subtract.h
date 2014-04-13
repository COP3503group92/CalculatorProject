#ifndef SUBTRACT_H
#define SUBTRACT_H

#include <iostream>
using namespace std;
#include "Operations.h"


class Subtract : public Operations
{
    public:
        Subtract();
		Subtract(Number* a, Number* b);
        virtual ~Subtract();
        Number* evaluate();
    protected:
    private:
		Number* a;
		Number* b;
        string cl = "-";
};

#endif // SUBTRACT_H
