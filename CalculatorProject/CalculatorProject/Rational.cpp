/*
 * Rational.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: Michael Kemerer
 */

#include "Rational.h"

Rational::Rational(){
	this->numerator = new Integer(1);
	this->denominator = new Integer(2);
}

Rational::Rational(Number* numerator){
	this->numerator = numerator;
	this->denominator = new Integer(1);
}

Rational::Rational(Number* numerator, Number* denominator){
	this->numerator = numerator;
	this->denominator = denominator;
}
Rational::~Rational() {
		this->numerator->~Number();
		this->denominator->~Number();
}

void Rational::simplify(){
	if (this->numerator->getType() == this->denominator->getType()){
		if (this->numerator->getType() == "Integer"){
			Integer* numer = dynamic_cast<Integer*>(this->numerator);
			Integer* denom = dynamic_cast<Integer*>(this->denominator);
			int num = numer->getValue();
			int den = denom->getValue();
			int& n = num;
			int& d = den;
			leastCommonDenom(n, d);
			numer->setValue(num);
			denom->setValue(den);
			this->numerator = numer;
			this->denominator = denom;
		}
		else if (this->numerator->getType()=="Rational")
		{
			Rational* rat1 = dynamic_cast<Rational*>(this->numerator);
			Rational* rat2 = dynamic_cast<Rational*>(this->denominator);
			Multiply* numMult = new Multiply(rat1->numerator, rat2 - denominator);
			Multiply* denomMult = new Multiply(rat1->denominator, rat2->numerator);
			Rational* simplerRat = new Rational(numMult->evaluate(), denomMult->evaluate());
			simplerRat->simplify();
		}
		else if (this->numerator->getType() == "Pi"){
			Pi* firstPi = dynamic_cast<Pi*>(this->numerator);
			Pi* secondPi = dynamic_cast<Pi*>(this->denominator);
			Rational* newCo = new Rational(firstPi->getCoefficent(), secondPi->getCoefficent());
			Subtract* exSub = new Subtract(firstPi->getExponent, secondPi->getExponent);
			Number* newEx = exSub->evaluate();
			Pi* answer = new Pi();
			answer->setExponent(newEx);
			answer->setCoefficient(newCo);
			this->numerator = answer;
			this->denominator = new Integer(1)
		}
	}
}

void Rational::leastCommonDenom(int& n, int& d){
	for (int i = 0; i < d; i++){
		if (n%i == 0 && d%i == 0){
			n = n / i;
			d = d / i;
			leastCommonDenom(n, d);
		}
	}
}
