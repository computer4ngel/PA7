#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include "Stack.h"

using namespace std;

bool checkOperatorOnStackPrecedence(char, char);
int precedence(char c);
int stackPrecedence(char curCheck);
int currentPrecedence(char stackCheck);
bool isOperand(string c);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);
		bool isOperator(char check);
};

#endif