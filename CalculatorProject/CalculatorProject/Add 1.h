#pragma once

#include "Includes.h"

class Add : public Operations
{
    public:
        Add();
        virtual ~Add();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "+";
};

#endif // ADD_H
