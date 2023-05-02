#include "Calculator.h"
#include <fstream>

/*

----Credit to Mark Sanghera for helping me with function design here----

*/

void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

// TODO: finish this function
bool checkOperatorOnStackPrecedence(char operatorOnStack, char currentOperator) {
	bool returnCheck = stackPrecedence(operatorOnStack) < currentPrecedence(currentOperator);
	return returnCheck;
}

// TODO: finish this function
/*While there are items in the INFIX expression:
	If item is an operand:
		Add it to the POSTFIX expression
	Else if item is a (:
		Push it onto the stack
	Else if item is a ):
		While item on top of the stack is not a (:
			Pop that item and add it to the POSTFIX expression
		Pop ( and throw it away
		Throw ) away
	Else: // arithmetic operator
		While stack is not empty and item on the top of stack has a 
higher precedence than the current item:
			Pop stack and add that operator to the POSTFIX expression
		Push current item
	Advance to next item in INFIX expression
While stack is not empty:
	Pop and add item to POSTFIX expression
*/
string Calculator::convertInfixToPostfix(string infix) {
	string value;
	string postfix;

	stack.destroyList();
	cout << "Infix: " << infix << endl;
	stack.destroyList(); // make sure stack is clear
	for(int i = 0; i < infix.length(); i++) {
		value = toupper(infix[i]);
		if(isOperand(value)) {
			postfix += value;
		}
		else if(value == "(") {
			stack.push(value);
		}
		else if(value == ")") {
			while(stack.peek() != "(") {
				postfix += stack.pop();
			}
			stack.pop();
		}
		// arithmetic operator
		else {
			while(!stack.isEmpty() && checkOperatorOnStackPrecedence(stack.peek()[0], value[0])) {
				postfix += stack.pop();
			}
			stack.push(value);
		}
	}
	while(!stack.isEmpty()) {
		postfix += stack.pop();
	}
	cout << "Postfix: " << postfix << endl;
	return postfix;
	}

// TODO: finish this function
string Calculator::evaluatePostfix(string postfix) {
		/*While there are items in the POSTFIX expression:
	If current item is an operand:
		Push it onto the stack
	Else: // operator
		Pop the stack and “attach” the operand popped to the right of the operator
		Pop the stack again and “attach” the operand popped to the left of the operator
		Evaluation and push the result
	Advance to the next item in the POSTFIX expression
	Pop the stack one more time to get the result
	*/
	string value;
	return ""; // TODO: fix this
}

bool Calculator::isOperator(char check) {
	switch(check) {
	case '+':
		//cout << "Item is operand";
		return true;
	case '-':
		//cout << "Item is operand";
		return true;
	case '*':
		//cout << "Item is operand";
		return true;
	case '/':
		//cout << "Item is operand";
		return true;
	case '^':
		//cout << "Item is operand";
		return true;
	case '(':
		//cout << "Item is operand";
		return true;
	case ')':
		//cout << "Item is operand";
		return true;
	default:
		//cout << "Not an operand";
		return false;
	}
	
}

int currentPrecedence(char curCheck) {
	switch (curCheck)
	{
	case '(':
		return 100;

	case ')':
		return 0;

	case '^':
		return 6;

	case '*':
	case '/':
	case '%':
		return 3;

	case '+':
	case '-':
		return 1;

	default:
		cout << "Operator: " << curCheck << " is not valid" << endl;
	}
	return -1;
}

int stackPrecedence(char stackCheck) {
		/*	           (	)	^	*	/	%	+	-
	On stack	   0	N/A	5	4	4	4	2	2
	*/
	switch (stackCheck)
	{
	case '(':
		return 0;

	case '^':
		return 5;

	case '*':
	case '/':
	case '%':
		return 4;

	case '+':
	case '-':
		return 2;

	default:
		cout << "Operator: " << stackCheck << " is not valid" << endl;
	}
	return -1;
}

bool isOperand(string c) {
	return (c[0] >= 'A' && c[0] <= 'Z');
}