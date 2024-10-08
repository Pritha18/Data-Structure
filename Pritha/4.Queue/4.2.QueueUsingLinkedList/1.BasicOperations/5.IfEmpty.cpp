/*
	5.Check if Empty
	Write a program to check if the queue is empty using a linked list.
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

Node* head;

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

	head = head->next;
}

int front() {
	if (NULL == head) {
		cout << "Error!!! Queue is empty" << endl;
		return -404;
	}

	return head->data;
}

int rear() {
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
	cout << "How many nodes you want to push in the queue: ";
	cin >> num;

	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		push(value);
		cout << "Front value is: " << front() << endl;
		cout << "Rear value is: " << rear() << endl;
	}

	pop();

	cout << "Front value is: " << front() << endl;
	cout << "Rear value is: " << rear() << endl;

	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}

	return 0;
}
