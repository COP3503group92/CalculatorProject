// LIBRARY INCLUDES
#include "LibraryIncludes.h"

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

// Storage
vector <string> inputExpression;	// To Store the input that user entered at first
vector <string> expressionResult;	// To store an expression result
vector <double> result;				// To store floating point value of user's answer
int ans;							// 

// Prototypes
int menu();
bool ComputeNewOperation();
void help();
void historyMenu();


int main() {
	bool terminateProgram = false;
	int menuChoice = 0;
	
	while(terminateProgram == false) {
		menuChoice = menu();
		cout << endl;
		switch(menuChoice){
		case 1: terminateProgram = ComputeNewOperation();
			break;
		case 2: historyMenu();
			break;
		case 3: help();
			break;
		case 0: terminateProgram = true;
			break;
		}// Close switch statement
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
		cout << "3. Help" << endl;
		cout << "4. Quit" << endl << endl;

		cout << "Enter a menu choice: ";
		cin >> selection;

		if(cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			
			cout << "Invalid input!!" <<endl;
			cout << "Enter and integer\n" <<endl;
			quit = false;
		}
		else if ((selection < 1) || (selection > 4)) {
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
			if( !result.empty() ) {
				ans = result.back();
				cout << "Enter an expression: ans ";
				getline(cin, input);
			}
			else {
				cout << "Error!\nNo operations have been performed yet!"<<endl <<endl;
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

			expressionResult.push_back("hah");
			expressionResult.push_back("lmao");
			expressionResult.push_back("seriously");

			result.push_back(45);
			result.push_back(75);
			result.push_back(65);

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
	
	do {
		cout << "---------------------------------------------------------------------" << endl;
		cout << "                          <<   History!   >>                         " << endl << endl;
		cout << "1. Display floating value" << endl;
		cout << "2. Set ans " << endl;
		cout << "3. Back" << endl << endl;

		cout << "Enter a selection: ";
		cin >> selection;

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
			cout << "Display floating value (Y or N): ";
			cin >> floating;
	
			while( cin.fail() || (floating != 'y') && (floating != 'n') && (floating != 'Y') && (floating != 'N') ) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Wrong Input!\n"<< endl;
				cout << "Enter Y for yes and N for No: ";
				cin >> floating;
			}
		

			if( !inputExpression.empty() && (floating == 'y' || floating == 'Y') ) {
				int print = 1;
				int counter = inputExpression.size() - 1;
				while( counter >= 0 ) {
					cout << print << "\t" << inputExpression.at(counter) 
						<<"\t\t"  << expressionResult.at(counter) <<"\t\t"  << result.at(counter) << endl;
					counter--;
					print++;
				}
			}
			else if( !inputExpression.empty() && (floating == 'n' || floating == 'N') ) {
				int print = 1;
				int counter = inputExpression.size() - 1;
				while( counter >= 0 ) {
					cout << print << "\t" << inputExpression.at(counter) 
						<<"\t\t"  << expressionResult.at(counter)<< endl;
					counter--;
					print++;
				}
			}
			else {
				cout << "No operations has been performed yet" << endl;
				cout << "No history available yet" << endl << endl;
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

