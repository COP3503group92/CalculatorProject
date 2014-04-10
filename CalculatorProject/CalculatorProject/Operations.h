#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Operations
{
    public:
        Operations();
        virtual ~Operations();
        virtual void evaluate(Number a, Number b)=0;

    private:
};

#endif // OPERATIONS_H
