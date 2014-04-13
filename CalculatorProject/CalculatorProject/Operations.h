#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Number.h"
#include "Integer.h"

class Operations
{
public:
        virtual ~Operations();
        virtual Number* evaluate(Number*a, Number* b)=0;

    private:
};

#endif // OPERATIONS_H
