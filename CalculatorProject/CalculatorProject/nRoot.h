#ifndef nROOT_H
#define nROOT_H

#include "Includes.h"

class nRoot : public Operations
{
    public:
        nRoot();
        virtual ~nRoot();
        Number* evaluate();
    protected:
    private:
        string cl = "rt";
};

#endif // nROOT_H
