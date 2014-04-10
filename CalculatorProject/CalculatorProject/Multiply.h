#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <iostream>
using namespace std;
#include <Operations.h>


class Multiply : public Operations
{
    public:
        Multiply();
        virtual ~Multiply();
        void evaluate();
    protected:
    private:
};

#endif // MULTIPLY_H
