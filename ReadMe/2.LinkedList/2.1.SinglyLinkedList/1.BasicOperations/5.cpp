/*
	5.Delete from Beginning:
	Write a program to delete a node from the beginning of a singly linked list.
*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node() { }

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

Node* head;

void insertAtEnd(int value) {
	Node *tempNode = new Node(value);
	
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
	Node *tempNode = new Node(value);

	if (NULL == head) {
		head = tempNode;
		return;
	}

	tempNode -> next = head;
	head = tempNode;
}

void deleteFromBegin() {
	if (NULL == head){
		cout << "Error!" << endl;
		return;
	}

	if (NULL == head -> next) {
		head = NULL;
		return;
	}

	head = head -> next;
}

void display() {
	Node* travel = head;

	while(NULL != travel) {
		cout << travel -> data << " ";
		travel = travel -> next;
	}

	cout << endl;
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

		insertAtEnd(value);
	}

	display();
	
	deleteFromBegin();

	display();
	
	return 0;
}