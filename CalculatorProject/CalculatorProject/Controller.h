#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <stdexcept>
#include <stack>
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
	Controller();
	~Controller(void);

	// Parsing Methods ==================================================
	vector<Number*> parseQueue(vector<string> input);
	vector<Number*> convertToNumberVector(vector<string> queue);

	// Shunting Yard Methods ============================================
	void setString(string);
	void setQueue(vector<string>);
	string getS();
	vector<string> getQueue();

	void removeSpaces();
	bool isNumber(char);
	bool isSpecialNumber(string);

	bool isOperator(char);
	bool isOperator(string);
	bool isOpenParen(char);
	bool isOpenParen(string);
	bool isCloseParen(char);
	bool isCloseParen(string);

	string operatorToString(char);
	int precedence(string);
	void addMissingOPerator();
	void finalStringCleanUp();

	void toVector();
	void reversePolish();
	void printInfo();

	void calculate();

private:
	string s;
	stack <string> operators;
	vector <string> expression;
	vector <string> queue;
	vector <string> answer;

};

#endif
