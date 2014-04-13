#ifndef EXPONENTIATE_H_
#define EXPONENTIATE_H_

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
