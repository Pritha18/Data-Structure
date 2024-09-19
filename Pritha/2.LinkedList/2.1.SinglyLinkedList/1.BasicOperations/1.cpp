/*
	1.Create a Linked List and Display it:
	Write a program to create a singly linked list and traverse and display 
	elements of the list.
*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* head;

void display() {
	Node* travel = head;

	while(NULL != travel) {
		cout << travel -> data << " ";
		travel = travel -> next;
	}
}

int main(int argc, char const *argv[])
{
	head = NULL;

	Node firstNode;
	firstNode.data = 5;
	firstNode.next = NULL;

	if (NULL == head) {
		head = &firstNode;
	}

	Node secondNode;
	secondNode.data = 7;
	secondNode.next = NULL;

	firstNode.next = &secondNode;

	Node thirdNode;
	thirdNode.data = 9;
	thirdNode.next = NULL;

	secondNode.next = &thirdNode;

	display();

	return 0;
}