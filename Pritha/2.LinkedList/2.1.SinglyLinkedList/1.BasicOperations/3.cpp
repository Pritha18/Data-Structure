/*
	3.Insert at Beginning:
	Write a program to insert a node at the beginning of a singly linked list.
*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void insertAtEnd(int value) {

	Node *tempNode = new Node();
	tempNode -> data = value;
	tempNode -> next = NULL;
	
	if (NULL == head) {
		head = tempNode;
		return;
	}

	Node* travel = head;

	while(NULL != travel -> next) {
	
		travel = travel -> next;
	}

	travel -> next = tempNode;
}

void insertAtBegin(int value) {

	Node *tempNode = new Node();
	tempNode -> data = value;
	tempNode -> next = NULL;

	if (NULL == head) {
		head = tempNode;
		return;
	}

	tempNode -> next = head;

	head = tempNode;
}

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

	int num;
	cout << "How many nodes you want to insert in the linked list: ";
	cin >> num;
	
	for (int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		insertAtBegin(value);
	}

	display();
	
	return 0;
}