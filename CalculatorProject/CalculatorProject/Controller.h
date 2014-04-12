#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
#include <sstream>
#include <vector>

#include "Number.h"
#include "Integer.h"
#include "Rational.h"

#include "SpecialCase.h"
#include "NatE.h"
#include "Pi.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"

#include "Operations.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"
#include "nRoot.h"

using namespace std;

class Controller{

public:
	vector<Number*> parseQueue(vector<string> input);
	vector<Number*> convertToNumberVector(vector<string> queue);

};

#endif
