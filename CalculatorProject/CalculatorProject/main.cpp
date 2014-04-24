// LIBRARY INCLUDES
#include <iostream>

// CONTROLLER
#include "Controller.h"

// OPERATIONS
#include "Operations.h"
#include "Add.h"
// #include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponentiate.h"

// NUMBER
#include "Number.h"
#include "Integer.h"
#include "Rational.h"
#include "SpecialCase.h"
#include "Pi.h"
#include "NatE.h"
#include "Log.h"
#include "Root.h"
#include "Expression.h"
#include "Operator.h"

// Main
#include<fstream>

// using namespace std;

// Storage
vector <string> inputExpression;	// To Store the input that user entered at first
vector <string> expressionResult;	// To store an expression result
vector <double> result;				// To store floating point value of user's answer
int ans;							// 

// Prototypes
string LoadOperations();
void SaveOperations();
int menu();
bool ComputeNewOperation();
void help();
void historyMenu();

using namespace std;

int main() {
	string ans_value = "";
	string defaultSave = "";
	bool terminateProgram = false;
	int menuChoice = 0;
	ofstream outFile;

	cout << "Welcome! Calculator 2.0 is very  easy to use and in less than a minute" << endl;
	cout << "you can become a master at operating the calculator to it full function" << endl;
	cout << "ality. But before doing so, you must first do one important thing." << endl << endl;
	cout << "Select option 5 to learn the correct syntax. Otherwise, enjoy! " << endl;
	cout << "---------------------------------------------------------------------" << endl << endl;
	
	while(terminateProgram == false) {
		menuChoice = menu();
		cout << endl;

		switch(menuChoice){
		case 1: terminateProgram = ComputeNewOperation();
			break;
		case 2: historyMenu();
			break;
		case 3: defaultSave = LoadOperations();
			break;
		case 4: SaveOperations();
			break;
		case 5: help();
			break;
		case 0: terminateProgram = true;
			break;
		}// Close switch statement
	}

	if(!defaultSave.empty()) {
		// Saving equations to file
		outFile.open(defaultSave);
		int i = 0;
		while (i < inputExpression.size()) {
			outFile << inputExpression.at(i) << endl;
			outFile << expressionResult.at(i) << endl;
			outFile << result.at(i) << endl;
		}
		outFile.close();
	}

	cout << "\nGoodbye!" <<endl << endl; 
	system("pause");
	return 0;
}

// Function:	menu()
// Parameters:	None
// Description:	This function keep printing the menu to the user.
//				until a valid choice is seleted. It also check for input faiures.
//				it return the menu choice (an integer).
// Return:		selection (Menu choice selected by the user)
int menu() {
	int selection = 0;
	bool quit;
	do {
		cout << "*********************************************************************" << endl;
		cout << "                            Calculator 2.0                           " << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << "                           << Main Menu >>                           " << endl;
		cout << "1. Compute new expression" << endl;
		cout << "2. Review previous expressions" << endl;
		cout << "3. Load operations from file" << endl;
		cout << "4. Save operations to file" << endl;
		cout << "5. Help" << endl;
		cout << "0. Quit" << endl << endl;

		cout << "Enter a menu choice: ";
		cin >> selection;

		if(cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			
			cout << "Invalid input!!" <<endl;
			cout << "Enter and integer\n" <<endl;
			quit = false;
		}
		else if ((selection < 0) || (selection > 5)) {
			cout << "Invalid Input!"<<endl;
			cout << "Enter a choice (1-4)\n" <<endl;
			quit = false;
		}
		else {
			quit = true;
		}
	} while(!quit);
	return selection;
}

// Function:	compute()
// Parameter:	None
// Description:	This function will do all the stuffs nececessary
//				to get the answers in expression as well as in decimal
//				value
// return:		None
bool ComputeNewOperation() {
	
	// Local variables
	string input;
	bool quit = false;
	bool exitCompute = false;
	bool ans = false;
	bool bad_input = false;
	

	// To clean any last bad (\n) character in the cin
	cin.ignore();

	do {
		// Create an object of the class Shunting yard
		Controller* op = new Controller();

		cout << "---------------------------------------------------------------------" << endl;
		cout << "                          <<   Calculate   >>                        " << endl << endl;
		cout << "- Type an expression to calculate: " << endl;
		cout << "- Type \"back\" to go back to Main Menu: " << endl;
		cout << "- Type \"quit\" to exit Calculator 2.0!: " << endl << endl;

		cout << "Enter an expression: ";
		getline(cin, input);

		if (input == "ans") {
			// If the answer is empty then set answer to last operation
			if( ans == 0 && !result.empty() ) {
				ans = result.back();
				cout << "Enter an expression: ans ";
				getline(cin, input);
			}
			else if (ans == 0 && result.empty()) {
				cout << "Error!\nNo operations have been performed yet!" << endl << endl;
			}
			else {
				// whatever that is in ans add it to
				cout << "Enter an expression: ans ";
				getline(cin, input);
			}
		}
		else if(input == "quit") {
			quit = true;
			exitCompute = true;
		}
		else if(input == "back") {
			// Do nothing because the user wish to go back
			// to main menu
			exitCompute = true;
		}
		else {
			try {
				op->setString(input);
			}
			catch( exception &e ) {
				cout << e.what() << endl;
				bad_input = true;
			}
			if(!bad_input) {	
				// Call to the correponding operations goes inside
				// this block
				op->removeSpaces();
				op->addMissingOPerator();
				op->finalStringCleanUp();

				op->toVector();
				op->reversePolish();
				op->printInfo();

				vector<Number*> queue = op->parseQueue(op->getQueue());

				cout << endl << endl;

				for (int sizeCount = 0; sizeCount < queue.size(); sizeCount++){

					cout << "Result [" << sizeCount << "] = " << queue[sizeCount]->toString() << endl;

				}

				// Add expression
				inputExpression.push_back(input);
				expressionResult.push_back(queue[0]->toString());
				result.push_back(0);

				// This is the  end of the block to the operations
				cout << endl;
				// Delete the ShuntingYard object using the destructor
				op->~Controller();
			}
			cout << endl;
		}

	} while( !exitCompute );

	return quit;
}

string LoadOperations() {
	// These vectors will be used to copy the inputs of the storage vectors
	vector<string> file_inputs;
	vector<string> file_results;
	vector<double> file_floatresults;

	while (!inputExpression.empty() && !expressionResult.empty() && !result.empty()) {
		// Access the last element in array to copy over
		file_inputs.push_back(inputExpression.back());
		file_results.push_back(expressionResult.back());
		file_floatresults.push_back(result.back());

		// Remove last element (Technically decrementing counter)
		inputExpression.pop_back();
		expressionResult.pop_back();
		result.pop_back();
	}

	string fileName = "";
	ifstream textFile;

	cout << "Enter the name of a file (.txt) to read from: ";
	cin >> fileName;
	cout << endl;

	textFile.open(fileName);
	while (!textFile.is_open()) {
		cout << "Invalid File name!" << endl;
		cout << "Enter a valid file name: ";
		cin >> fileName;
		cout << endl;
	}

	// For test purposes
	cout << "Vector size before load: " << file_inputs.size() << endl;

	// Read file until the end of file is reached
	while (!textFile.eof()) {
		string temp;
		string temp1;
		double temp2;
		textFile >> temp >> temp1 >> temp2;
		inputExpression.push_back(temp);
		expressionResult.push_back(temp1);
		result.push_back(temp2);
	}

	// add the temporary vector back to the orginal
	while (!file_inputs.empty() && !file_results.empty() && !file_floatresults.empty()) {
		// Access the last element in array to copy over
		inputExpression.push_back(file_inputs.back());
		expressionResult.push_back(file_results.back());
		result.push_back(file_floatresults.back());

		// Remove last element (Technically decrementing counter)
		file_inputs.pop_back();
		file_results.pop_back();
		file_floatresults.pop_back();
	}

	// For test purposes
	cout << "Vector size after load: " << file_inputs.size() << endl;

	textFile.close();
	return fileName;
}

void SaveOperations(){
	int choice;
	ofstream outFile;

	cout << "---------------------------------------------------------------------" << endl;
	cout << "                          <<   Save Menu   >>                        " << endl << endl;

	cout << "1. Save" << endl;
	cout << "2. Save As" << endl << endl;

	cout << "Enter a choice: ";
	cin >> choice;

	while (cin.fail() || (choice < 0 && choice > 2)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Invalid input!!" << endl;
		cout << "Enter (1 or 2)";
		cin >> choice;
	}
	if (choice == 2) {
		string temp = "";
		cout << "Save as: ";
		cin >> temp;

		if (temp != "cancel") {
			// Add extension to name
			temp = temp + string(".txt");

			// Saving equations to file
			outFile.open(temp);
			int i = 0;
			while (i < inputExpression.size()) {
				outFile << inputExpression.at(i) << endl;
				outFile << expressionResult.at(i) << endl;
				outFile << result.at(i) << endl;
			}
			outFile.close();
			cout << "Operations saved to file \"" << temp << ".\"" << endl << endl;
		}
	}
	else {
		// Just save to what was opened
		cout << "Operations saved to file" << endl << endl;
	}
}

// Function:	historyMenu()
// Parameter:	None
// Description:	This method works perfectly so far except it is missing the option 
//				to ask user whether her or she needs decimal values
// return:		none
void historyMenu() {
	char floating;
	int in;
	int selection;
	int hist;
	
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                          <<   History!   >>                         " << endl << endl;
	
	// First print out the inputs witht the result in expression format
	int print = 1;
	int counter = inputExpression.size() - 1;
	while (counter >= 0) {
		cout << print << "\t" << inputExpression.at(counter)
			<< "\t\t" << expressionResult.at(counter) << endl;
		counter--;
		print++;
	}

	do {
		cout << "---------------------------------------------------------------------" << endl;
		cout << "                          <<   History!   >>                         " << endl << endl;
		cout << "1. Display floating value" << endl;
		cout << "2. Set ans " << endl;
		cout << "3. Back" << endl << endl;

		cout << "Enter a selection: ";
		cin >> selection;
		cout << endl;

		if(cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			
			cout << "Invalid input!!" <<endl;
			cout << "Enter and integer\n" <<endl;
		}
		else if ((selection < 1) || (selection > 3)) {
			cout << "Invalid Input!"<<endl;
			cout << "Enter a choice (1-3)\n" <<endl;
		}
		else if (selection == 1) {
			if(inputExpression.empty()){
				cout << "No operations have been performed yet" << endl;
			}
			else {
				int print = 1;
				int counter = inputExpression.size() - 1;
				while (counter >= 0) {
					cout << print << "\t" << inputExpression.at(counter)
						<< "\t\t" << expressionResult.at(counter) << "\t\t" << result.at(counter) << endl;
					counter--;
					print++;
				}
			}
		}
		else if(selection == 2) {
			int sel;
			cout << "Enter the history to set to \"ans\": ";
			cin >> sel;

			if(!result.empty()) {
				ans = result.at((result.size() - sel));
			}
			else {
				cout << "No operations have been performed yet"<< endl;
			}

		}
		else {
			// User must have selected 0
			// Do nothing. Just got back to main menu
		}
	}while(selection != 3);
}

// Function:	void help()
// Parameter:	None
// Description:	This method print out the instruction to the user
//				it also has a one option submenu which allow the user 
//				to go back to the main menu once the user is done reading
// Return		none
void help() {
	int in = 0;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "                           << User Manual >>                         " << endl << endl;
	cout << "Contents" << endl;
	cout << "Calculator 2.0 has the following menu" << endl;
	cout << "- Main Menu" << endl;
	cout << "- Calculate Menu" << endl;
	cout << "- History Menu" << endl;
	cout << "- Help Menu" << endl << endl;

	cout << "Navigating through Calculator 2.0\n";
	cout << "- Calculate, History, and the Help Menu can only be access at the\n";
	cout << "Main Menu by entering the number associated with that menu.\n" << endl;

	cout << "Calculate Menu allows the user to enter an expression to solve.\n";
	cout << "When inside the Calculate Meny, users are allowed to enter\n";
	cout << "the keyword \"back\" to go back to the Main Menu, or the keyword\n";
	cout << "\"quit\"\ to exit Calculator 2.0\n" << endl;

	cout << "History Menu allows the user to see previous calculations computed.\n";
	cout << "It also allows the user to see floating values of past result\n";
	cout << "as well as selecting an answer to be used in another operations\n" << endl;

	cout << "Loading and Saving Operations\n";
	cout << "Load and Save are not submenu. Load is used to load operations\n";
	cout << "from a file provided that the correct filename is entered and the\n";
	cout << "file is not empty\n";
	cout << "Save can used to save update the open file or save to a new file.\n"<< endl;

	cout << "Syntax\n";
	cout << "Always use lowercase letters.\n";
	cout << "Use parentheses as needed\n\n";

	cout << "Basic Operations:\n";
	cout << "Addition	: number 1 + number 2\n";
	cout << "Substraction	: number 1 - number 2\n";
	cout << "Multiplication	: number 1 * number 2\n";
	cout << "Division	: number 1 / number 3\n";
	cout << "Exponent	: base ^ exponent\n\n";

	cout << "Logarithm syntax:\n";
	cout << "log base	: log_(base):(operand)\n";
	cout << "log base 10	: log_10: or log:\n";
	cout << "natural log	: log_e:  or ln:\n\n";

	cout << "Root Syntax	:\n";
	cout << "Any root	: nth rt:(operand)\n";
	cout << "Square root	: 2rt:(operand) or sqrt:(operand)\n\n";

	cout << "Other Syntax	:\n";
	cout << "Euler's Number	: \"e\"\n";
	cout << "Pi		: \"pi\"\n" << endl;

	cout << "Restrictions\n";
	cout << "Calculator 2.0 is case sensitive. To prevent error messages,\n";
	cout << "always follow the accepted input format and avoid using any\n";
	cout << "uppercase letters.\n";
	cout << "Example; \"pi\" and \"Pi\" are not the same inputs\n";
	cout << "---------------------------------------------------------------------\n" << endl;


	cout << "Enter \"9\" to go back to the main menu:";
	cin >> in;
	while (cin.fail() || (in != 9)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wrong Input!\n" << endl;
		cout << "Enter the number \"9\" if you wish to go back to the Main Menu:";
		cin >> in;
	}
	cout << endl;
}

