#ifndef EXPONENTIATE_H
#define EXPONENTIATE_H

#include "Includes.h"

class Exponentiate : public Operations
{
    public:
        Exponentiate();
        virtual ~Exponentiate();
        Number* evaluate();
		void set
    protected:
    private:
        string cl = "^";
};

#endif // EXPONENTIATE_H
