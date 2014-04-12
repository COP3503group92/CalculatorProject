#ifndef EXPONENTIATE_H
#define EXPONENTIATE_H

#include <iostream>
using namespace std;
#include <Operations.h>


class Exponentiate : public Operations
{
    public:
        Exponentiate();
        virtual ~Exponentiate();
        Number evaluate();
    protected:
    private:
        string cl = "^";
};

#endif // EXPONENTIATE_H
