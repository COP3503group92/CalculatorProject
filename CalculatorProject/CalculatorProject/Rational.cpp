/*
 * Rational.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: Michael Kemerer
 */

#include "Rational.h"

/*
 * A rational number can be a simple integer, with a denominator of 1.
 */
	Rational::Rational(int numeratorInt){
		this->numeratorInt=numeratorInt;
		this->denominatorInt=1;

	}

	/*
	 * A rational number can also be a traditional fraction. It should not matter whether the fraction
	 * is improper or not.
	 */
	Rational::Rational(int numeratorInt, int denominatorInt){
		this->numeratorInt=numeratorInt;
		this->denominatorInt=denominatorInt;
	}

	/*
	 * It is possible to have one of our special cases (logs, pi's, e's, etc.) or even another
	 * Rational be divided by an integer. I don't expect us to be handling Special Cases like this,
	 * but if we decide to create a rational whenever we see a "/", then I figured this should be
	 * an option. We can always have a simplify function that outputs a SpecialCase with a modified
	 * coefficient or modify that Rational.
	 */
	Rational::Rational(Number* numeratorSpec, int denominatorInt){
		this->numeratorSpec=numeratorSpec;
		this->denominatorInt=denominatorInt;
	}

	/*
	 * We can also have one of our SpecialCases or Rationals to be a denominator. Our new Rational
	 * will be able to simplify itself, and our special case can TECHNICALLY be just changed to
	 * numerator*SpecialCase^-1 . Or we can keep it as a Rational.
	 */
	Rational::Rational(int numeratorInt, Number* denominatorSpec){
		this->numeratorInt=numeratorInt;
		this->denominatorSpec=denominatorSpec;
	}

	/*
	 * The final case: dividing all sorts of SpecialCases. Later evaluation will determine whether
	 * the numerator and denominator are compatible and perform the appropriate simplification.
	 */
	Rational::Rational(Number* numeratorSpec, Number* denominatorSpec){
		this->numeratorSpec=numeratorSpec;
		this->denominatorSpec=denominatorSpec;
	}
	Rational::~Rational() {
	numeratorSpec->~Number();
	denominatorSpec->~Number();
}

