#ifndef DIVIDE_H
#define DIVIDE_H

#include <iostream>
using namespace std;
#include "Operations.h"


class Divide : public Operations
{
    public:
        Divide();
        virtual ~Divide();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "/";
};

#endif // DIVIDE_H
