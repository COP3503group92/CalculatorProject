#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Includes.h"

class Operations
{
public:
        virtual ~Operations();
        virtual Number* evaluate()=0;

    private:
};

#endif // OPERATIONS_H
