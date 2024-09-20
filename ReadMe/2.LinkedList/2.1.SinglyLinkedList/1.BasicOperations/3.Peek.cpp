/*
	3.Peek Operation:
	Write a program to implement the peek operation in a stack using a linked list.
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

Node* head = NULL;

void push(int value) {
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

void pop() {
	if (NULL == head){
		cout << "Error! There is no node" << endl;
		return;
	}
	if (NULL == head -> next) {
		head = NULL;
	}
	Node* travel = head;
	while(NULL != travel -> next -> next) {
		travel = travel -> next;
	}
	travel -> next = NULL;
}
int top() {
	Node* travel = head;
	while(NULL != travel -> next) {
		travel = travel -> next;
	}
	return travel -> data;
}

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	for(int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		push(value);
		cout << "top value is: " << top() << endl;
	}

	pop();
	cout << "top value is: " << top() << endl;

	return 0;
}