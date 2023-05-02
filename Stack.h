#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// Stack inherits from LinkedList
class Stack : public LinkedList {
	public:
	   // common stack operations
	   void push(string);
	   string pop();
	   string peek();
	   bool isEmpty();
};

#endif