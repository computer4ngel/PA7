#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}

void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}

void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

// TODO: finish this function
void LinkedList::insertAtFront(string newValue) {
	Node* temp = new Node;
	temp->value = newValue;
	temp->next = head;
	head = temp;
}

// TODO: finish this function
string LinkedList::deleteAtFront() {
	Node* temp = head;
	head = head->next;

	delete temp;

	return head->value; // TODO: fix this
}