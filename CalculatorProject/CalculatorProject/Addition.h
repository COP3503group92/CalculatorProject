#ifndef ADDITION_H
#define ADDITION_H

#include <iostream>
using namespace std;
#include <Operations.h>



class Addition : public Operations
{
    public:
        Addition();
        virtual ~Addition();
        void evaluate();
    protected:
    private:
};

#endif // ADDITION_H
