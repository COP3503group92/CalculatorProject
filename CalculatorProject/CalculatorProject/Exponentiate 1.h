#pragma once

#include "Includes.h"

class Exponentiate : public Operations
{
    public:
        Exponentiate();
        virtual ~Exponentiate();
        Number* evaluate(Number* a, Number* b);
    private:
        string cl = "^";
};

#endif // EXPONENTIATE_H
