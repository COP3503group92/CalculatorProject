#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <iostream>
using namespace std;
#include "Operations.h"


class Multiply : public Operations
{
    public:
        Multiply();
        virtual ~Multiply();
        Number* evaluate();
    protected:
    private:
        string cl = "*";
};

#endif // MULTIPLY_H
