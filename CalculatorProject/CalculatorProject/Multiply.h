#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Includes.h"

class Multiply : public Operations
{
    public:
        Multiply();
        virtual ~Multiply();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "*";
};

#endif // MULTIPLY_H
