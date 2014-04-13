#ifndef DIVIDE_H
#define DIVIDE_H

#include "Includes.h"

class Divide : public Operations
{
    public:
        Divide();
        virtual ~Divide();
        Number evaluate();
    protected:
    private:
        string cl = "/";
};

#endif // DIVIDE_H
