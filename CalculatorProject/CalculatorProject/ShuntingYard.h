#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class ShuntingYard
{
public:
	ShuntingYard(void);
	~ShuntingYard(void);

	// Usual Methods
	void setString(string);
	void setQueue(vector<string>);
	string getS();
	vector<string> getQueue();

	// Previous methods
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

