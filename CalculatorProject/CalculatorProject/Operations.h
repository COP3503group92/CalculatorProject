#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Includes.h"

class Operations
{
    public:
        Operations();
        virtual ~Operations();
        virtual Number* evaluate(Number* a, Number* b)=0;

    private:
};

#endif // OPERATIONS_H
