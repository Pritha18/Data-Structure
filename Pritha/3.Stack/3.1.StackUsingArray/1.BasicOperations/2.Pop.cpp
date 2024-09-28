/*
	2.Pop Operation:
	Write a program to implement the pop operation in a stack using an array.
*/

#include <iostream>
using namespace std;

int stack[5005];
int topIndex = -1;

void push(int value) {
	stack[++topIndex] = value;
}

void pop() {
	topIndex--;
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
	}

	pop();
	
	return 0;
}