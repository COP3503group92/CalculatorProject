#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Includes.h"

class Operations
{
public:
        virtual ~Operations();
        virtual Number* evaluate(Number*a, Number* b) = 0;

};

#endif // OPERATIONS_H
