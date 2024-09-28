/*
	5.Check if Full:
	Write a program to check if the stack is full using an array.
*/

#include <iostream>
using namespace std;

const int SIZE = 5005;
int stack[SIZE];
int topIndex = -1;

bool isEmpty() {
	return topIndex < 0 ? true : false;
}

bool isFull() {
	return topIndex + 1 == SIZE ? true : false;
}

void push(int value) {
	if (isFull()) {
		cout << "Error!!! Stack is full" << endl;
		return;
	}

	stack[++topIndex] = value;
}

void pop() {
	if (isEmpty()) {
		cout << "Error! There is no node in stack" << endl;
		return;
	}

	topIndex--;
}

int top() {
	return stack[topIndex];
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