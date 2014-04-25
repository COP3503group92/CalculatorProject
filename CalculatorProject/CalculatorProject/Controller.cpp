#include "Controller.h"

Controller::Controller()
{
	string s;
}

Controller::~Controller(void)
{
}

// Parsing Methods ====================================================================================================================================

vector<Number*> Controller::convertToNumberVector(vector<string> queue){

	vector<Number*> numberVector;

	for(int i = 0; i < queue.size(); i++){

		if((queue[i][0] == '-' && queue[i][1] == 'p') || queue[i][0] == 'p'){

			bool neg = false;
			if(queue[i][0] == '-'){
				neg = true;
			}

			Number* piObject = new Pi(neg);
			piObject->simplify();

			numberVector.push_back(piObject);

		} else if(queue[i][0] == 'l'){

			Number* logObject = new Log(numberVector[numberVector.size() - 2], numberVector[numberVector.size() - 1]);
			logObject->simplify();
		
			numberVector.push_back(logObject);
			numberVector.erase(numberVector.begin() + numberVector.size() - 2);
			numberVector.erase(numberVector.begin() + numberVector.size() - 2);

		} else if((queue[i][0] == '-' && queue[i][1] == 'e') || queue[i][0] == 'e'){

			bool neg = false;
			if(queue[i][0] == '-'){
				neg = true;
			}

			Number* eObject = new NatE(neg);
			eObject->simplify();

			numberVector.push_back(eObject);

		} else if(queue[i][0] == 'r'){

			Number* rtObject = new Root(numberVector[numberVector.size() - 1], numberVector[numberVector.size() - 2]);
			rtObject->simplify();
			numberVector.push_back(rtObject);
			numberVector.erase(numberVector.begin() + numberVector.size() - 2);
			numberVector.erase(numberVector.begin() + numberVector.size() - 2);
		}
		else if (queue[i][0] == '+' || (queue[i][0] == '-' && queue[i].size() == 1) || queue[i][0] == '*' || queue[i][0] == '/' || queue[i][0] == '^'){
			if (queue[i][0] == '^'){
				Exponentiate* exp = new Exponentiate();
				Number* expObject = exp->evaluate(numberVector[numberVector.size() - 2], numberVector[numberVector.size() - 1]);
				numberVector.push_back(expObject);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);

			}
			else if (queue[i][0] == '+'){
				/*Number* opObject = new Operator(queue[i]);

				numberVector.push_back(opObject);
				Joe's original code for the entire operator section. 
				Keeping it in case we give up with complex cases
				*/
				Add* add = new Add();
				Number* sum = add->evaluate(numberVector[numberVector.size() - 2], numberVector[numberVector.size() - 1]);
				numberVector.push_back(sum);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);

			}
			else if (queue[i][0] == '-'){
				Subtract* sub = new Subtract();
				Number* dif = sub->evaluate(numberVector[numberVector.size() - 2], numberVector[numberVector.size() - 1]);
				numberVector.push_back(dif);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);

			}
			else if (queue[i][0]=='*'){
				Multiply* mult = new Multiply();
				Number* product = mult->evaluate(numberVector[numberVector.size() - 2], numberVector[numberVector.size() - 1]);
				numberVector.push_back(product);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);

			}
			else if (queue[i][0] == '/'){
				Number* ans = new Rational(numberVector[numberVector.size() - 2], numberVector[numberVector.size() - 1]);
				ans->simplify();
				numberVector.push_back(ans);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);
				numberVector.erase(numberVector.begin() + numberVector.size() - 2);
			}
		} else {

			Number* intObject = new Integer(queue[i]);
			
			numberVector.push_back(intObject);

		}

	}

	numberVector[0]->simplify();
	return numberVector;

}

vector<Number*> Controller::parseQueue(vector<string> queue){

	vector<Number*> input = convertToNumberVector(queue);

	for (int i = 0; i < input.size(); i++){

		if (input[i]->getType() == "Operator"){

			Operator* inputCast = dynamic_cast<Operator*>(input[i]);

			if (inputCast->getOperator() == "+"){

				Add addObject = Add();

				Number* result = addObject.evaluate(input[i - 2], input[i - 1]);

				input.erase(input.begin() + i - 1);
				input.erase(input.begin() + i - 1);

				input[i - 2] = result;

				i = 0;

			} // END + OPERATOR ===============================================================================

			else if (inputCast->getOperator() == "-"){

				Subtract subtractObject = Subtract();

				Number* result = subtractObject.evaluate(input[i - 2], input[i - 1]);

				input.erase(input.begin() + i - 1);
				input.erase(input.begin() + i - 1);

				input[i - 2] = result;

				i = 0;

			} // END - OPERATOR ===============================================================================

			else if (inputCast->getOperator() == "*"){

				Multiply multiplyObject = Multiply();

				Number* result = multiplyObject.evaluate(input[i - 2], input[i - 1]);

				input.erase(input.begin() + i - 1);
				input.erase(input.begin() + i - 1);

				input[i - 2] = result;

				i = 0;

			} // END * OPERATOR ===============================================================================

			else if (inputCast->getOperator() == "/"){

				Divide divideObject = Divide();

				Number* result = divideObject.evaluate(input[i - 2], input[i - 1]);

				input.erase(input.begin() + i - 1);
				input.erase(input.begin() + i - 1);

				input[i - 2] = result;

				i = 0;

			} // END / OPERATOR ===============================================================================

			else if (inputCast->getOperator() == "^"){

				Exponentiate exponentiateObject = Exponentiate();

				Number* result = exponentiateObject.evaluate(input[i - 2], input[i - 1]);

				input.erase(input.begin() + i - 1);
				input.erase(input.begin() + i - 1);

				input[i - 2] = result;

				i = 0;

			} // END ^ OPERATOR ===============================================================================

		} // END OPERATOR CHECK SECTION =======================================================================

		else if (input[i]->getType() == "Log"){

			input[i]->simplify();
			Number* result = input[i];

			input[i] = result;

		}
		else if (input[i]->getType() == "Root"){

			input[i]->simplify();
			Number* result = input[i];

			input[i] = result;

		}

	}

	return input;

}

// Shunting Yard Methods ====================================================================================================================================

// SET METHODS
void Controller::setString(string in)
{
	int leftParen = 0;
	int rightParen = 0;
	if (in.empty()) {
		throw exception("Error! Empty expression");
	}

	int i = 0;
	while (i < in.length()) {
		if (in.at(i) == '(') { leftParen++; }
		if (in.at(i) == ')') { rightParen++; }
		
		/*/ Invalid Character Error Check
		if( (isNumber(i) && (in.at(i) != 'e' || in.at(i) != 'i'
		|| in.at(i) != 'l' || in.at(i) != 'o' || in.at(i) != 'g' ||
		in.at(i) != 'p' || in.at(i) != 'q' || in.at(i) != 'r' ||
		in.at(i) != 's' || in.at(i) != 't') && in.at(i) != '(' &&
		in.at(i) != ')' && !isOperator(in.at(i))) ) {
		throw exception ("Invalid character in expression");
		}
		*/

		// Logaritm Syntax Error Check
		if (in.at(i) == 'l') {
			string temp = "";
			// If a character is 'l.' It must be log: log_ or ln:
			while ((i < in.length()) && (in.at(i) != '(' && in.at(i) != 'e' && in.at(i) != 'p' && !isNumber(in.at(i)))) {
				temp.push_back(in.at(i));
				i++;
			}
			i--;
			if (temp != "log:" && temp != "log_" && temp != "ln:") {
				throw exception("Logarithm Syntax Error!");
			}
		}
		// Square Root Syntax Error
		if (in.at(i) == 's') {
			string temp = "";
			int j = 0;
			while ((i + j) < in.length() && j < 5) {
				temp.push_back(in.at(i + j));
				j++;
			}
			if (temp != "sqrt:") {
				throw exception("Square Root Syntax Error");
			}
			i = i + j;
		}
		// Root Error Check
		if (in.at(i) == 'r') {
			if (i == 0 && in.at(i) == 'r') {
				throw exception("Error! nth root not specified");
			}
			if ((i - 1 >= 0) && !isNumber(in.at(i - 1)) && in.at(i - 1) != ')') {
				throw exception("Error! nth root not specified");
			}

			string temp = "";
			int j = 0;
			while (((i + j) < in.length()) && (j < 3)) {
				temp.push_back(in.at(i + j));
				j++;
			}
			if (temp != "rt:") {
				throw exception("nth root syntax Error");
			}
		}
		// Operator error check
		if ((i + 1 < in.length()) && isOperator(in.at(i) && isOperator(in.at(i + 1))) && in.at(i + 1) != '-') {
			throw exception("Operator Error");
		}
		// Dividing by zero error
		if ((i >= 0) && (i + 1 < in.length()) && (in.at(i) == '/' && in.at(i + 1) == '0')) {
			throw invalid_argument("Error! Cannot divide by zero");
		}
		i++;
	}

	if (leftParen < rightParen) {
		throw exception("Error! Missing \"(\"");
	}
	if (leftParen > rightParen) {
		throw exception("Error! Missing \")\"");
	}
	s = in;
}
void Controller::setQueue(vector<string> input)
{
	queue = input;
}

// GET METHODS
string Controller::getS()
{
	return s;
}
vector<string> Controller::getQueue()
{
	return queue;
}

void Controller::removeSpaces(){
	//creates a new expression string without any spaces
	string out;
	int i = 0;
	while (i < s.length()){
		char a = s.at(i);
		if (a != ' '){
			out = out + a;
		}
		i++;
	}

	cout << "Remove Space Check\n" << out << endl << endl;
	s = out;
}

// Method:		isNumber(char in)
// Description:	Take an input and check to see if it is
//				a digit. Return true if true else return false
// Return		true or false
bool Controller::isNumber(char in){
	//if statement checks if value is a number
	int character = (int)in;
	if ((character >= 48) && (character <= 57)){
		return true;
	}
	else {
		return false;
	}
}

// Method:		isNumber(char in)
// Description:	Take an input and check to see if it is
//				a digit. Return true if true else return false
// Return		true or false
bool Controller::isSpecialNumber(string in){
	//if statement checks if input is pi or e
	if ((in == "PI") || (in == "Pi") || (in == "pI") || (in == "pi")){
		return true;
	}
	else if ((in == "e")) {
		return true;
	}
	else {
		return false;
	}
}

// Method:		isOperator(char)
// Parameter:	char op
// Desrciption:	Check if the chararacter is one of the assigned character +,-,*,/
//				return true if it is and false if not
// return:		bool	
bool Controller::isOperator(char op)
{
	if ((op == '+') || (op == '-') || (op == '*') ||
		(op == '^') || (op == '/')) {

		return true;
	}
	else {
		return false;
	}
}
bool Controller::isOperator(string op)
{
	if ((op == "+") || (op == "-") || (op == "*") ||
		(op == "^") || (op == "/")) {

		return true;
	}
	else {
		return false;
	}
}
bool Controller::isOpenParen(char in){
	//returns true if the char in is a '('
	int character = (int)in;
	if (character == 40) {
		return true;
	}
	else {
		return false;
	}
}
bool Controller::isOpenParen(string in){
	//returns true if the char in is a '('
	if (in == "(") {
		return true;
	}
	else {
		return false;
	}
}
bool Controller::isCloseParen(char in){
	//returns true if the char in is a ')'
	int character = (int)in;
	if (character == 41) {
		return true;
	}
	else {
		return false;
	}
}
bool Controller::isCloseParen(string in){
	//returns true if the char in is a ')'
	if (in == ")") {
		return true;
	}
	else {
		return false;
	}
}

// Method:		operatorToString(char)
// Parameter:	char op
// Description:	This method converts the operation sign
//				to string types so that it can be stored in the string vector
std::string Controller::operatorToString(char op)
{
	string temp;
	temp.push_back(op);
	return temp;
}

// Method:		precedence(string)
// parameters:	string operation
// Description:	This method takes in a string which should be a character (+,-,*,/)
//				except in the case that it is log_. It returns a number corresponding
//				to the operation string.
// Return:		int a number
int Controller::precedence(std::string operation)
{
	if ((operation == "^")) {
		return 2;
	}
	else if ((operation == "/") || (operation == "*")) {
		return 1;
	}
	else if ((operation == "+") || (operation == "-")) {
		return 0;
	}
	else {
		// For now return -1 if you do not know what it is
		// This is just in case log_, e, sqrt, and rt
		return -1;
	}
}

// Method:		addMissingOperator(string)
void Controller::addMissingOPerator()
{
	// NEW UPDATED CODES
	string out = "";
	int par = 0;
	bool leftPar = false;
	for (int i = 0; i < s.length(); i++) {
		// For cases like this -(9)
		// Change to (-1)*(9)
		if ( (i == 0) && (s.at(i) == '-') ) {
			out.push_back('(');
			out.push_back(s.at(i));
			leftPar = true;
		}
		// Negative cases with the log: rt:
		else if (s.at(i) == '-' && !out.empty() && out.back() == ':') {
			out.push_back('(');
			out.push_back(s.at(i));
			leftPar = true;
		}
		// Cases for --
		else if (!out.empty() && out.back() == '-' && s.at(i) == '-') {
			// Case: --9 should yield 9
			if (s.at(0) == '-') {
				// Remove previous negative from out
				out.pop_back();
			}
			// Case 6--9 should yield 6+9
			else {
				// Replace -- by +
				out.pop_back();
				out.push_back('+');
			}
		}
		// cases like 3^-4 or 4/-5 or need to be taken into account
		else if ( (i-1 >= 0) && s.at(i) == '-' && !out.empty() && isOperator(out.back()) ) {
			if (leftPar && par == 0){
				par++;
			}
			out.push_back('(');
			out.push_back(s.at(i));
			leftPar = true;
		}
		// to add corresponding parenthese
		else if (isOperator(s.at(i)) && leftPar && par == 0) {
			out.push_back(')');
			out.push_back(s.at(i));
			leftPar = false;
		}
		// For log or ln or sqrt
		else if ((s.at(i) == 'l' || s.at(i) == 's') && i != 0) {
			if (leftPar && par == 0){ 
				out.push_back(')');
				leftPar = false;
			}
			out.push_back('*');
			out.push_back(s.at(i));
		}
		// For rt
		else if (s.at(i) == 'r' && leftPar && par == 0) {
			out.push_back(')');
			out.push_back(s.at(i));
			leftPar = false;
		}
		// If left parenthese
		else if (s.at(i) == '(') {
			out.push_back(s.at(i));
			par++;
		}
		else if (s.at(i) == ')') {
			out.push_back(s.at(i));
			par--;
			if (par == 0 && leftPar && (i+1) == s.length()){
				out.push_back(')');
				leftPar = false;
			}
		}
		else {
			out.push_back(s.at(i));
		}
	}
	while (par != 0) {
		out.push_back(')');
		par--;
	}
	if (leftPar) {
		out.push_back(')');
	}
	
	// OLD CODES TO ADD THE MISSING OPERATOR =====================================================
	/*
	string out = "";
	for (int i = 0; i < s.length(); i++) {
		// For cases like this -(9)
		// Change to (-1)*(9)
		if ((i == 0) && (i + 1 < s.length()) && (s.at(i) == '-') &&
			((isNumber(s.at(i + 1))) || (s.at(i + 1) == 'e') || (s.at(i + 1) == 'p')
			|| (isOpenParen(s.at(i + 1))))) {
			out.push_back('(');
			out.push_back(s.at(i));
			out.push_back('1');
			out.push_back(')');
			out.push_back('*');
			i++;
		}
		else if ((i == 0) && (i + 1 < s.length()) && (s.at(i) == '-') && (s.at(i + 1) == '-')) {
			i = i + 2;
		}
		else if ((i >= 0) && (i - 1 >= 0) && ((s.at(i) == '-')) && ((i + 2 < s.length()) &&
			(s.at(i + 1) == '-') && (s.at(i - 1) != '^'))) {
			if (s.at(i - 1) != '(') {
				out.push_back('+');
			}
			i = i + 2;
		}
		//else if( (i + 1 < s.length()) && s.at(i) == '^' && s.at(i+1) == '-' ) {

		//}
		// This is for cases like e() or 4(67)
		// If the previous character is a number or special
		if ((i > 0) && (s.at(i) == '(') &&
			(isNumber(s.at(i - 1)) || (s.at(i - 1) == 'p') || (s.at(i - 1) == 'e'))) {
			out.push_back('*');
		}
		else if ((i > 0) && (s.at(i - 1) == ')') && (s.at(i) == '(')) {
			out.push_back('*');
		}
		else if ((i > 0) && (s.at(i - 1) == ')') && !isOperator(s.at(i)) &&
			(s.at(i) != '(') && (s.at(i) != ')') && (s.at(i) != ':')) {
			out.push_back('*');
		}
		out.push_back(s.at(i));
	} */
	// END OF OLD CODES =================================================================================
	std::cout << "Missing Operator Check\n" << out << endl << endl;
	s = out;
}

// Method:		finalStringCleanUp(string in)
// Description:	This methods clean up the final string by adding extra parentheses
//				around the negative numbers to make ease the shunting yard method
//				Example: if the user entered 2*-7
void Controller::finalStringCleanUp()
{
	// NEW UPDATED CODES ================================================================================
	string out = "";
	int i = 0;
	while (i < s.length()) {
		if ((i - 1) >= 0 && s.at(i) == '-' && 
			(isOperator(s.at(i-1)) || s.at(i-1) == '(')) {
				out = out + string("(-1)*");
				
			}
		else {
			out.push_back(s.at(i));
		}
		i++;
	}
	
	// OLD CODES ========================================================================================
	/*
	string out = "";
	int i = 0;
	while (i < s.length())
	{
		if ((i >= 1) && (s.at(i - 1) == '-') && (isNumber(s.at(i)) || s.at(i) == 'p' || s.at(i) == 'e')) {
			out = "";
			out.push_back('(');
			out.push_back('-');
			out.push_back(s.at(i));
			i++;

			while ((i < s.length()) && (isNumber(s.at(i)) || !isOperator(s.at(i)))) {
				out.push_back(s.at(i));
				i++;
			}
			out.push_back(')');
		}
		else if ((i - 2 >= 0) && (!isNumber(s.at(i - 2)) && s.at(i - 2) != 'e' && s.at(i - 2) != 'i') &&
			(s.at(i - 1) == '-') && (s.at(i) == 'l')) {
			out = "";
			out = out + string("(-1)*");
			out.push_back(s.at(i));
			i++;
		}
		else if ((i > 0) && (isOperator(s.at(i - 1)) || isOpenParen(s.at(i - 1))) &&
			(s.at(i) == '-')) {
			out.push_back('(');
			out.push_back(s.at(i));
			i++;
			while ((i < s.length()) && (isNumber(s.at(i)) || !isOperator(s.at(i))) && s.at(i) != 'l') {
				out.push_back(s.at(i));
				i++;
			}
			if ( (i < s.length()) && s.at(i) == 'l') {
				out.push_back(')');
				out.push_back('*');
			}
			else {
				out.push_back(')');
			}
		}
		else {
			out.push_back(s.at(i));
			i++;
		}
	}
	*/
	// END OF OLD CODES ==========================================================================
	
	// If prarmeter is removed, uncommment
	// s = out;
	cout << "Final Clean Up Check\n" << out << endl << endl;
	s = out;
}


// Method:		toVector()
// Parameters:	None
// Description:	This method convert the given string to a vector
//				to make sure that every number is seperated correctly
//				Ex: (25*89-100)^79
// return:		None
void Controller::toVector()
{
	string temp = "";

	int i = 0;
	while (i < s.size()) {
		if (isNumber(s.at(i))) {
			string num = "";
			// Form the number
			while ((i < s.size()) && isNumber(s.at(i))) {
				num.push_back(s.at(i));
				i++;
			}
			// Add the number to the vector
			expression.push_back(num);

		}
		else if (isOperator(s.at(i))) {
			string oper = "";
			oper.push_back(s.at(i));
			// Add temp to vector then add operator
			expression.push_back(oper);
			i++;
		}
		else if (isOpenParen(s.at(i)) || isCloseParen(s.at(i))) {
			string par = "";
			par.push_back(s.at(i));
			// Add parenthese to the vector
			expression.push_back(par);
			i++;
		}
		else if (s.at(i) == ':') {
			/*
			expression.push_back(temp);
			temp = "";
			*/
			if ((i - 1 >= 0) && s.at(i - 1) != 't' && s.at(i - 1) != 'n' && s.at(i - 1) != 'g') {
				expression.push_back(":");
			}
			else {
			}
			i++;
		}
		// If it is not anything else
		else {
			bool log_ = false;
			// It must be a letter in this case of a special number, or log, or root
			while ((i < s.length()) && (!isOperator(s.at(i)) && !log_ &&
				!isCloseParen(s.at(i)) && !isOpenParen(s.at(i)) && s.at(i) != ':' && !isNumber(s.at(i)))) {
				// Form the special number
				temp.push_back(s.at(i));
				// In case that it is a log_
				if (s.at(i) == '_') {
					log_ = true;
				}
				i++;
			}
			// At this point, temp is either e or pi, rt, sqrt, ln, log, or log_
			if (isSpecialNumber(temp)) {
				expression.push_back(temp);
				temp = "";
			}
			else if (temp == "log_") {
				expression.push_back(temp);
				temp = "";
			}
			else if (temp == "rt") {
				expression.push_back(temp);
				temp = "";
			}
			else if (temp == "sqrt") {
				expression.push_back("2");
				expression.push_back("rt");
				temp = "";
			}
			else if (temp == "ln") {
				expression.push_back("log_");
				expression.push_back("e");
				temp = "";
			}
			else if (temp == "log") {
				expression.push_back("log_");
				expression.push_back("10");
				temp = "";
			}
			else if ((!expression.empty()) && (expression.back() == "ln")) {
				expression.pop_back();
				expression.push_back("log_");
				expression.push_back("e");
				temp = "";
			}
			else if ((!expression.empty()) && (expression.back() == "log")) {
				expression.pop_back();
				expression.push_back("log_");
				expression.push_back("10");
				temp = "";
			}
			else if ((!expression.empty()) && (expression.back() == "sqrt")) {
				expression.pop_back();
				expression.push_back("2");
				expression.push_back("rt");
				temp = "";
			}
		}
	}
}



// Method:		void reversePolish()
// Parameters:  none
// Description:	This method convert the a given object into a format that follows
//				the rules of PEMDAS, and put it in a way that is acceptable to
//				the computer
// Return:		None
void Controller::reversePolish()
{
	stack<string> operations;
	bool logInStack = false;
	bool removeLog = false;
	bool removeRt = false;

	// First make expressionVector a fitted vector to prevent furture headache
	expression.shrink_to_fit();

	int i = 0;
	while (i < expression.size()){
		// if it is an operator, Check precedence
		if (isOperator(expression.at(i))) {
			if (operations.empty()) {
				operations.push(expression.at(i));
			}
			// if the last operator 
			else if ((!operations.empty()) && isOpenParen(operations.top())) {
				operations.push(expression.at(i));
			}
			else if ((!operations.empty()) && operations.top() == "log_" && removeLog && expression.at(i) != "^") {
				queue.push_back(operations.top());
				operations.pop();
				if (!isCloseParen(expression.at(i))) {
					operations.push(expression.at(i));
				}
			}
			else if ((!operations.empty()) && operations.top() == "rt" && removeRt && expression.at(i) != "^") {
				queue.push_back(operations.top());
				operations.pop();
				operations.push(expression.at(i));
			}
			else if ((!operations.empty()) && (precedence(operations.top()) >= precedence(expression.at(i)))) {
				// Remove until operation top <= current operator or pararentheses
				while ((!operations.empty()) && !isOpenParen(operations.top()) && operations.top() != "log_" &&
					operations.top() != "rt" && ((precedence(operations.top()) >= precedence(expression.at(i))))) {
					queue.push_back(operations.top());
					operations.pop();
				}
				if (!operations.empty() && (operations.top() == "log_" || operations.top() == "rt" || operations.top() == "(")) {
					// If the top operation is ( or rt or log_
					operations.pop();
				}
				// Now add the operator to operations stack
				operations.push(expression.at(i));
			}
			else {
				// Add to operations
				operations.push(expression.at(i));

			}
			i++;
		}
		else if ((i >= 0) && (i < expression.size()) && expression.at(i) == "(") {
			operations.push(expression.at(i));
			i++;
		}
		else if ((i > 0) && (i < expression.size()) && expression.at(i) == ")") {
			// Loop as long as ( is not on the last element in operations
			// or operations is not empty
			while ((!operations.empty()) && (!isOpenParen(operations.top())) &&
				(operations.top() != "log_") && (operations.top() != "rt")) {
				queue.push_back(operations.top());
				operations.pop();
			}
			i++;
			if (!operations.empty() && operations.top() == "(") {
				// Remove the left parenthese
				operations.pop();
			}

			// In case of rt, or logBase
			if (!operations.empty() && operations.top() == "rt") {
				// Move rt to queue
				queue.push_back(operations.top());
				operations.pop();
			}
			else if (!operations.empty() && operations.top() == "log_" && removeLog) {
				queue.push_back(operations.top());
				operations.pop();
			}
		}
		else if ((expression.at(i) == ":")) {
			// Remove until log is on top of stack
			// Add to the operation stack
			while (!operations.empty() && operations.top() != "log_") {
				queue.push_back(operations.top());
				operations.pop();
			}
			if (!operations.empty() && operations.top() == "log_") {
				removeLog = true;
			}
			else {
				// Do absolutely nothing
			}
			i++;
		}
		else if ((expression.at(i) == "rt")) {
			// Add to the operation stack
			operations.push(expression.at(i));
			removeRt = true;
			i++;
		}
		else if ((expression.at(i) == "log_")) {
			// Add to the operation stack
			operations.push(expression.at(i));
			i++;
		}
		else {
			// In case of negative number put it as it is
			// Example -2, -e, -pi
			if ((i > 0) && !operations.empty() && expression.at(i - 1) == "-" &&
				isOpenParen(expression.at(i - 2).at(0))) {
				// String has to be concatenated
				string  temp;
				temp = operations.top() + expression.at(i);
				operations.pop();
				queue.push_back(temp);
				// Cases like log_(2rt:-4):(7-3)
				if (removeRt && !operations.empty() && (operations.top() == "rt")) {
					queue.push_back(operations.top());
					operations.pop();
				}
				i++;
			}
			else {
				// It must be a number or a special number 
				// Add to queue
				queue.push_back(expression.at(i));
				// Cases like log_(2rt:4):(7-3)
				if (removeRt && !operations.empty() && (operations.top() == "rt")) {
					queue.push_back(operations.top());
					operations.pop();
				}
				i++;
			}
		}
	}
	while (!operations.empty()) {
		queue.push_back(operations.top());
		operations.pop();
	}
}

void Controller::calculate()
{
	// loop through the polish vector
	for (int i = 0; i < queue.size(); i++) {

	}
}

void Controller::printInfo()
{
	cout << "Expression in vector" << endl;
	for (int i = 0; i < expression.size(); i++) {
		cout << expression.at(i) << "  ";
	}

	cout << endl;


	cout << "\nExpression in reversePolish vector" << endl;
	for (int i = 0; i < queue.size(); i++) {
		cout << queue.at(i) << "  ";
	}

}
