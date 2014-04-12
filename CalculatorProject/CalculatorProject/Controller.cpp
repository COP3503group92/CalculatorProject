#include "Controller.h"
#include "Multiply.h"

vector<string> Controller::parseQueue(vector<string> input){

	for (int i = 0; i < input.size(); i++){

		if (input[i] == "*"){

			// FIRST TERM ==================================================================

			if (input[i - 2].size() >= 3){

				bool fraction = false;
				bool negFraction = false;

				for (int j = 1; j < input[i - 2].size(); j++){

					if (input[i - 2][j] == '/'){

						fraction = true;

						if (input[i - 2][0] == '-'){

							negFraction = true;

						}

						if (input[i - 2][j + 1] == '-'){

							negFraction = true;

						}

						if (negFraction == false){

							string numerator = "";

							for (int k = 0; k < j; k++){

								numerator += input[i - 2][k];

							}

							string denomenator = "";

							for (int l = j + 1; l < input[i - 2].size(); l++){

								denomenator += input[i - 1][l];

							}

							Fraction* firstFraction = new Fraction(numerator, denomenator);

						}
						else if (negFraction == true) {

							string numerator = "-";

							for (int k = 1; k < j; k++){

								numerator += input[i - 1][k];

							}

							string denomenator = "";

							for (int l = j + 1; l < input[i - 1].size(); l++){

								denomenator += input[i - 1][l];

							}

							Fraction* firstFraction = new Fraction(numerator, denomenator);

						}

					}

					if (fraction == false){

						bool neg = false;

						if (input[i - 2][0] == '-'){
							neg = true;
							input[i - 2].erase(input[i - 2].begin());
						}

						int first = 0;
						istringstream(input[i - 2]) >> first;

						if (neg == true){
							first = first * (-1);
						}

						stringstream ss;
						ss << first;
						string firstString = ss.str();

						ss.clear();

						Fraction* firstFraction = new Fraction(firstString);

					}

				}

			} // END 3 TERM IF(1) ==================================================================
			else {

				bool neg = false;

				if (input[i - 2][0] == '-'){
					neg = true;
					input[i - 2].erase(input[i - 2].begin());
				}

				int first = 0;
				istringstream(input[i - 2]) >> first;

				if (neg == true){
					first = first * (-1);
				}

				stringstream ss;
				ss << first;
				string firstString = ss.str();

				ss.clear();

				Fraction* firstFraction = new Fraction(firstString);

			}

			// SECOND TERM ==================================================================

			if (input[i - 1].size() >= 3){

				bool fraction = false;
				bool negFraction = false;

				for (int j = 1; j < input[i - 1].size(); j++){

					if (input[i - 1][j] == '/'){

						fraction = true;

						if (input[i - 1][0] == '-'){

							negFraction = true;

						}

						if (input[i - 1][j + 1] == '-'){

							negFraction = true;

						}

						if (negFraction == false){

							string numerator = "";

							for (int k = 0; k < j; k++){

								numerator += input[i - 1][k];

							}

							string denomenator = "";

							for (int l = j + 1; l < input[i - 1].size(); l++){

								denomenator += input[i - 1][l];

							}

							Fraction* secondFraction = new Fraction(numerator, denomenator);

						}
						else if (negFraction == true) {

							string numerator = "-";

							for (int k = 1; k < j; k++){

								numerator += input[i - 1][k];

							}

							string denomenator = "";

							for (int l = j + 1; l < input[i - 1].size(); l++){

								denomenator += input[i - 1][l];

							}

							Fraction* secondFraction = new Fraction(numerator, denomenator);

						}

					}

					if (fraction == false){

						bool neg = false;

						if (input[i - 1][0] == '-'){
							neg = true;
							input[i - 1].erase(input[i - 1].begin());
						}

						int second = 0;
						istringstream(input[i - 1]) >> second;

						if (neg == true){
							second = second * (-1);
						}

						stringstream ss;
						ss << second;
						string secondString = ss.str();

						ss.clear();

						Fraction* secondFraction = new Fraction(secondString);

					}

				}

			} // END 3 TERM IF(2) ==================================================================
			else {

				bool neg = false;

				if (input[i - 1][0] == '-'){
					neg = true;
					input[i - 1].erase(input[i - 1].begin());
				}

				int second = 0;
				istringstream(input[i - 1]) >> second;

				if (neg == true){
					second = second * (-1);
				}

				stringstream ss;
				ss << second;
				string secondString = ss.str();

				ss.clear();

				Fraction* secondFraction = new Fraction(secondString);

			}

			// OPERATIONS HANDLING ==================================================================

			Fraction resultFraction = Multiply().evaluate(firstFraction, secondFraction); // MULTIPLY HERE

			string temp_string = resultFraction.toString;

			input.erase(input.begin() + i - 1);
			input.erase(input.begin() + i - 1);

			input[i - 2] = temp_string;

			i = 0;

		} // END OPERATOR SECTION ==================================================================

	} // END MAIN FOR ==================================================================

	return input;

}
