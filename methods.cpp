#include "methods.h"
using namespace std;

bool isValid(string exp)
{
	if (exp.length() == 0 || exp.length() == 1 || exp.length() == 2)
		return false;
	if (exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == '%' || exp[0] == '^')
		return false;
	
	int operatorCount = 0;
	int operandCount = 0;
	
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '^')
			operatorCount++;
		else if (exp[i] != ' ' && exp[i] != '\t')
			operandCount++;

		if (exp[i] == '(' || exp[i] == ')' || exp[i] == '[' || exp[i] == ']' || exp[i] == '{' || exp[i] == '}')
			return false;
	}
	
	if (operatorCount != operandCount - 1)
		return false;
	
	return true;
}

string postfixToPrefix(string postfix)
{
	if (!isValid(postfix))
		return " ";

	string prefix;
	stack<string> s;

	for (int i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '%' && postfix[i] != '^' && postfix[i] != ' ' && postfix[i] != '\t')
		{
			string x(1, postfix[i]);
			s.push(x);
		}
		else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^')
		{
			if (s.empty())
				return " ";

			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			string exp = postfix[i] + op2 + op1;
			s.push(exp);
		}
	}

	while (!s.empty())
	{
		prefix += s.top();
		s.pop();
	}

	return prefix;
}