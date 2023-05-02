#include "Stack.h"

// TODO: finish this function
void Stack::push(string newValue) {
   LinkedList *newNode = NULL; // Pointer to a new node
   LinkedList::insertAtFront(newValue);
}

// TODO: finish this function
string Stack::pop() {
   string newVal;
   //be sure to return popped value
   newVal = LinkedList::deleteAtFront();
	return newVal;
}

// TODO: finish this function
string Stack::peek() {
   if(head == NULL) {
      cout << "No value on stack.";
      return "";
   }
   else {
      return head->value;
   }
}

// TODO: finish this function
bool Stack::isEmpty() {
   if(head == NULL) {
      return true;
   }
   else {	
      return false; // TODO: fix this
   }
}