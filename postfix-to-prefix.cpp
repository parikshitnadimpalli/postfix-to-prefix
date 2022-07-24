#include "methods.h"
using namespace std;

int main()
{
	cout << "\t\t\t|--------Infix to Prefix conversion using a stack--------|" << endl << endl;
	cout << "\t\tNOTE: You can use any type of brackets. Just be sure to properly balance them in your expression :)" << endl;

	string msg, prefix, postfix;

	cout << endl << "Enter the postfix expression to be converted: ";
	getline(cin, postfix);
	prefix = postfixToPrefix(postfix);

	msg = prefix == " " || prefix == postfix ? "Invalid postfix expression entered!" : prefix; // Checking to see if user input is valid or not
	cout << endl << "The converted expression is:\n" << msg;

	return 0;
}