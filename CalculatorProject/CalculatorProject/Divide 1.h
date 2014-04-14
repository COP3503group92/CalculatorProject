#pragma once

#include "Includes.h"

class Divide : public Operations
{
    public:
        Divide();
        virtual ~Divide();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "/";
};

#endif // DIVIDE_H
