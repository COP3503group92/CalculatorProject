#ifndef nROOT_H_
#define nROOT_H_

#include "Includes.h"

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
