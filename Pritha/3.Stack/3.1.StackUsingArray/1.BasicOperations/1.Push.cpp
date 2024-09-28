/*
	1.Push Operation:
	Write a program to implement the push operation in a stack using an array.
*/

#include <iostream>
using namespace std;

int stack[5005];
int topIndex = -1;

// push for stack in array
void push(int value) {
	stack[++topIndex] = value;
}

// pop for queue in array
void pop() {
	front++;
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
	
	return 0;
}