#ifndef DIVIDE_H
#define DIVIDE_H

#include <iostream>
using namespace std;
#include <Operations.h>


class Divide : public Operations
{
    public:
        Divide();
        virtual ~Divide();
        void evaluate();
    protected:
    private:
};

#endif // DIVIDE_H
