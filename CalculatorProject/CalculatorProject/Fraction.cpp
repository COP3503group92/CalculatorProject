#include "Fraction.h"

Fraction::Fraction(){

	this->numerator = "";
	this->denomenator = "";

}

Fraction::Fraction(string numerator, string denomenator){

	this->numerator = numerator;
	this->denomenator = denomenator;

}

Fraction::Fraction(string numerator){

	this->numerator = numerator;
	this->denomenator = "1";

}

string Fraction::getNumerator(){

	return this->numerator;

}

string Fraction::getDenomenator(){

	return this->denomenator;

}

void Fraction::setNumerator(string numerator){

	this->numerator = numerator;

}

void Fraction::setDenomenator(string denomenator){

	this->denomenator = denomenator;

}

string Fraction::toString(){

	string returnString = numerator + "/" + denomenator;
	return returnString;

}