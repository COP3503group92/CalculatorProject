#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Includes.h"

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
