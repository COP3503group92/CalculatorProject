#ifndef ADD_H
#define ADD_H

#include <iostream>
using namespace std;
#include <Operations.h>



class Add : public Operations
{
    public:
        Add();
        virtual ~Add();
        Number evaluate();
    protected:
    private:
        string cl = "+";
};

#endif // ADD_H