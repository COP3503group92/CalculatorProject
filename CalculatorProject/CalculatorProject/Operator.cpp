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
	return this->op;
}

string Operator::getType(){
	return typeName;
}

string Operator::toString(){
	return this->op;
}
void Operator::simplify(){

}


