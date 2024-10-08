/*
	4.Check if Empty:
	Write a program to check if the stack is empty using a linked list.
*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node() { }

	Node(int data) {
		this->data = data;
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

	while(NULL != travel->next) {
		travel = travel->next;
	}

	travel->next = tempNode;
}

void pop() {
	if (NULL == head){
		cout << "Error! There is no node" << endl;
		return;
	}

	if (NULL == head->next) {
		head = NULL;
	}

	Node* travel = head;

	while(NULL != travel->next->next) {
		travel = travel->next;
	}

	travel->next = NULL;
}

int top() {
	if (NULL == head){
		cout << "Error! There is no node in stack" << endl;
		return -404;
	}

	Node* travel = head;

	while(NULL != travel->next) {
		travel = travel->next;
	}

	return travel->data;
}

bool isEmpty() {
	return head == NULL ? true : false;
}

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		push(value);
		cout << "top value is: " << top() << endl;
	}

	pop();
	cout << "top value is: " << top() << endl;

	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	return 0;
}
