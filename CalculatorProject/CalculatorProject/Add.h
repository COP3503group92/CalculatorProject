#ifndef ADD_H
#define ADD_H

#include "Includes.h"

class Add : public Operations
{
    public:
        Add();
        virtual ~Add();
        Number* evaluate();

    private:
        string cl = "+";
};

#endif // ADD_H
