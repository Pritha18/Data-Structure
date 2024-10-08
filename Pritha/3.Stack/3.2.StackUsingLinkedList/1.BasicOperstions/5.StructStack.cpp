/*
	Stack implementation with Structure way
*/

#include <iostream>
using namespace std;

struct Stack
{
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

	Stack() {
		head = NULL;
	}

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
		if (isEmpty()){
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
};

int main(int argc, char const *argv[])
{
	Stack prithaStack;

	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	if (prithaStack.isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		prithaStack.push(value);
		cout << "top value is: " << prithaStack.top() << endl << endl;
	}

	prithaStack.pop();
	cout << "after pop once" << endl;
	cout << "top value is: " << prithaStack.top() << endl;

	if (prithaStack.isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	return 0;
}
