/*
	1.Create a Linked List and Display it:
	Write a program to create a singly linked list and traverse and display 
	elements of the list.
*/

#include <iostream>
using namespace std;


/*
	Singly linked list have two parts

	1. Data(Value)
	2. Address - Address of next node 
*/
struct Node
{
	int data;
	// since, this pointer will hold the next Node's address
	// so, we need to declare Node type pointer to hold next Node's address
	
	// it's like, when we are trying to store int type variable's address 
	// that time we declare a int type pointer variable

	// similarly, here we need to hold Node type variable's address
	// that's why we are declaring Node type pointer variable
	Node* next;
};

// global head
// variable named head's scope is global
// it will alive in entire code from this line
Node* head;

void display() {
	// helper pointer to traverse
	Node* travel = head;

	while(NULL != travel) {
		cout << travel -> data << " ";
		travel = travel -> next;
	}
}

int main(int argc, char const *argv[])
{
	head = NULL;

	// add first node

	// create it first
	Node firstNode;
	firstNode.data = 5;
	firstNode.next = NULL;

	// link it to the linked list
	if (NULL == head) {
		head = &firstNode;
	}

	// add the second node
	// create the second node
	Node secondNode;
	secondNode.data = 12;
	secondNode.next = NULL;

	// now let's add it to the first node's end
	firstNode.next = &secondNode;


	// add the third node
	// create the third node
	Node thirdNode;
	thirdNode.data = 7;
	thirdNode.next = NULL;

	// link to second node's end
	secondNode.next = &thirdNode;

	// now display the linked list
	display();

	return 0;
}