#include "Includes.h"


Root::Root()
{
}


Root::~Root()
{
}

Root::Root(Number* operand, Number* root, Number* coefficient, Number* exponent){
	this->coefficient = coefficient;
	this->exponent = exponent;
	this->operand = operand;
	this->root = root;
}
void Root::simplify(){
	
}
