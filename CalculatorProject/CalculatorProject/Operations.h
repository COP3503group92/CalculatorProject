#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
using namespace std;


class Operations
{
    public:
        Operations();
        virtual ~Operations();
        virtual void evaluate()=0;

    private:
};

#endif // OPERATIONS_H
