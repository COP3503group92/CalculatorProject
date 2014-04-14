#pragma once

#include "Includes.h"


class Subtract : public Operations
{
    public:
        Subtract();
        virtual ~Subtract();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "-";
};

#endif // SUBTRACT_H
