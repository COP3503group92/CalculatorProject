#pragma once

#include "Number.h"

class Operations
{
    public:
        Operations();
        virtual ~Operations();
        virtual Number* evaluate(Number* a, Number* b)=0;

    private:
};