#ifndef nROOT_H
#define nROOT_H

#include <iostream>
using namespace std;
#include "Operations.h"


class nRoot : public Operations
{
    public:
        nRoot();
        virtual ~nRoot();
        Number* evaluate(Number* a, Number* b);
    protected:
    private:
        string cl = "rt";
};

#endif // nROOT_H
