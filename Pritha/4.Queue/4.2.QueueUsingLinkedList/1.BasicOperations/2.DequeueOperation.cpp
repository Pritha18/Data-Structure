/*
	2.Dequeue Operation(Pop)
	Write a program to implement the dequeue operation in a queue using a linked list.
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

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the queue: ";
	cin >> num;

	for(int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		push(value);
	}

	pop();

	return 0;
}
