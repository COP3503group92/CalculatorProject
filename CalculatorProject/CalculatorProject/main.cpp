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
		cout << "***********************************************************" <<endl;
		cout << "                       Calculator 2.0                      " <<endl;
		cout << "-----------------------------------------------------------" <<endl;
		cout << "                      << Main Menu >>                      " << endl;
		cout << "1. Compute new expression"<<endl;
		cout << "2. Review previous expressions" <<endl;
		cout << "3. Help" <<endl;
		cout << "4. Quit" <<endl <<endl;

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
	
	cout << "-----------------------------------------------------------" << endl;
	cout << "                   <<   Calculate   >>                     " << endl << endl;

	// To clean any last bad (\n) character in the cin
	cin.ignore();

	do {
		// Create an object of the class Shunting yard
		Controller* op = new Controller();

		cout << "- Type \"back\" to go back to Main Menu: " << endl;
		cout << "- Type \"quit\" to exit Calculator 2.0!: " << endl << endl;

		cout << "Enter an expression: ";
		getline(cin, input);

		if (input == "ans") {
			if( !result.empty() ) {
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
				
			// Call to the correponding operations goes inside
			// this block
			op->removeSpaces();
			op->addMissingOPerator();
			op->finalStringCleanUp();

			op->toVector();
			op->reversePolish();
			op->printInfo();
				

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
	int hist;
		cout << "-----------------------------------------------------------" << endl;
		cout << "                    <<   History!   >>                     " << endl << endl;
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
					<<"\t\t"  << result.at(counter)<< endl;
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

// Function:	void help()
// Parameter:	None
// Description:	This method print out the instruction to the user
//				it also has a one option submenu which allow the user 
//				to go back to the main menu once the user is done reading
// Return		none
void help() {
	int in = 0;
	cout << "-----------------------------------------------------------" << endl;
	cout << "                    << Instructions >>                     " << endl << endl;
	cout << "This page is under construction" << endl << endl;
	cout << "Enter \"9\" to go back to the main menu:";
	cin >> in;
	while( cin.fail() || (in != 9) ) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wrong Input!\n"<< endl;
		cout << "Enter the number \"9\" if you wish to go back to the Main Menu:";
		cin >> in;
	}
	cout << endl;
}
