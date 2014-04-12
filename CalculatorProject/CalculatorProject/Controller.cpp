#include "Controller.h"

vector<Number*> Controller::convertToNumberVector(vector<string> queue){

	vector<Number*> numberVector;

	for(int i = 0; i < queue.size(); i++){

		if((queue[i][0] == '-' && queue[i][1] == 'p') || queue[i][0] == 'p'){

			bool neg = false;
			if(queue[i][0] == '-'){
				neg = true;
			}

			Pi* piObject = new Pi(neg);
			piObject->simplify();

			numberVector.push_back(piObject);

		} else if(queue[i][0] == 'l'){

			// go back for complexities later

			Log* logObject = new Log(numberVector[numberVector.size() - 1], numberVector[numberVector.size() - 2]);
			logObject->simplify();

			numberVector.push_back(logObject);

		} else if((queue[i][0] == '-' && queue[i][1] == 'e') || queue[i][0] == 'e'){

			bool neg = false;
			if(queue[i[0] == '-'){
				neg = true;
			}

			NatE* eObject = new NatE(neg);
			eObject->simplify();

			numberVector.push_back(eObject);

		} else if(queue[i][0] == 'r'){

			Root* rtObject = new Root(numberVector[numberVector.size() - 1], numberVector[numberVector.size() - 2]);
			rtObject->simplify();

			numberVector.push_back(rtObject);

		} else if(queue[i][0] == '+' || queue[i][0] == '-' || queue[i][0] == '*' || queue[i][0] == '/' || queue[i][0] == '^'){

			Operator* opObject = new Operator(queue[i]);

			numberVector.push_back(opObject);

		} else {

			Integer* intObject = new Integer(queue[i]);

			numberVector.push_back(intObject);

		}

	}

	return numberVector;

}

vector<Number*> Controller::parseQueue(vector<string> queue){

	vector<Number*> input = convertToNumberVector(queue);

	for(int i = 0; i < input.size(); i++){

		if(input[i]->getType() == "Operator"){

			if(input[i]->getOperator() == "+"){

				if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "Integer"){

					Integer* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "Rational"){

					Rational* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "Expression"){

					Expression* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "NatE"){

					NatE* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "Pi"){

					Pi* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "Log"){

					Log* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Add::evaluate(input[i - 2], input[i - 1])->getType() == "Root"){

					Rational* result = Add::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				}

			} // END + OPERATOR ===============================================================================

			if(input[i]->getOperator() == "-"){

				if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "Integer"){

					Integer* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "Rational"){

					Rational* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "Expression"){

					Expression* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "NatE"){

					NatE* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "Pi"){

					Pi* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "Log"){

					Log* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Subtract::evaluate(input[i - 2], input[i - 1])->getType() == "Root"){

					Rational* result = Subtract::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				}

			} // END - OPERATOR ===============================================================================

			if(input[i]->getOperator() == "*"){

				if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "Integer"){

					Integer* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "Rational"){

					Rational* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "Expression"){

					Expression* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "NatE"){

					NatE* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "Pi"){

					Pi* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "Log"){

					Log* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Multiply::evaluate(input[i - 2], input[i - 1])->getType() == "Root"){

					Rational* result = Multiply::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				}

			} // END * OPERATOR ===============================================================================

			if(input[i]->getOperator() == "/"){

				if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "Integer"){

					Integer* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "Rational"){

					Rational* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "Expression"){

					Expression* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "NatE"){

					NatE* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "Pi"){

					Pi* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "Log"){

					Log* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Divide::evaluate(input[i - 2], input[i - 1])->getType() == "Root"){

					Rational* result = Divide::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				}

			} // END / OPERATOR ===============================================================================

			if(input[i]->getOperator() == "^"){

				if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "Integer"){

					Integer* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "Rational"){

					Rational* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "Expression"){

					Expression* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "NatE"){

					NatE* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "Pi"){

					Pi* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "Log"){

					Log* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				} else if(Exponentiate::evaluate(input[i - 2], input[i - 1])->getType() == "Root"){

					Rational* result = Exponentiate::evaluate(input[i - 2], input[i - 1]);

					input.erase(input.begin() + i - 1);
					input.erase(input.begin() + i - 1);

					input[i - 2] = result;

					i = 0;

				}

			} // END ^ OPERATOR ===============================================================================

		}

	}

	return input;

}
