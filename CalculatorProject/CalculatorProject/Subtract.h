#ifndef SUBTRACT_H
#define SUBTRACT_H

#include <iostream>
using namespace std;
#include "Operations.h"


class Subtract : public Operations
{
    public:
        Subtract();
        virtual ~Subtract();
        Number evaluate();
    protected:
    private:
        string cl = "-";
};

#endif // SUBTRACT_H
