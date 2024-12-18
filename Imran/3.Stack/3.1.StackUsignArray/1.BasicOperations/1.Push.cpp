/*
	1.Push Operation:
	Write a program to implement the push operation in a stack using an array.
*/

#include <iostream>
using namespace std;

// global array for stack
int stack[5005];

// initially top index is -1
// -1 denotes stack is empty
int topIndex = -1;

// push for stack in array
void push(int value) {
	stack[++topIndex] = value;
}

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		push(value);
	}
	
	return 0;
}