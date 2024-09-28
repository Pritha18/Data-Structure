/*
	StackStruct
*/

#include <iostream>
using namespace std;

const int SIZE = 5005;

struct Stack
{
	int stack[SIZE];
	int topIndex = -1;

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

	bool isEmpty() {
		return topIndex < 0 ? true : false;
	}

	bool isFull() {
		return topIndex + 1 == SIZE ? true : false;
	}
};


int main(int argc, char const *argv[])
{
	Stack pritha;

	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	if (pritha.isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		int value;
		cin >> value;

		pritha.push(value);
		cout << "top value is: " << pritha.top() << endl;
	}

	pritha.pop();

	cout << "top value is: " << pritha.top() << endl;

	if (pritha.isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	
	return 0;
}