#include "Operator.h"


Operator::Operator()
{
	this->op = "+";
}


Operator::~Operator()
{
}

Operator::Operator(string oper){
	this->op = oper;
}

string Operator::getOperator(){
	return op;
}

string Operator::getType(){
	return TYPE_NAME;
}

void Operator::simplify(){

}


