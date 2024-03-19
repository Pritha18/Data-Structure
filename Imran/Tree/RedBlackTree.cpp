
#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node
{
	int data;
	Node* parent
	Node* left;
	Node* right;
	Color color;

	Node() { }

	Node(int value) {
		data = value;
		parent = NULL;
		left = NULL;
		right = NULL;
		color = RED;
	}
};


Node* insertNode(Node* root, int value) 
{
	if (NULL == root) {
		// creating new node and assign it to root
		root = new Node(value); // creating new node with value
		return root;
	}

	if (value < root -> data) {
		root -> left = insertNode(root -> left, value);
	} else {
		root -> right = insertNode(root -> right, value);
	}

	return root;
}

Node* leftRotate(Node* root, Node* x) {
	// got the reference of x right child
	// which is y
	Node* y = x -> right;

	// move y left child to x right child
	x -> right = y -> left;

	// since we moved the y node's left child to x node's right
	// If y left child is not equal to null then 
	// we need to update the parent of the child from y to x;
	if (NULL != y -> left) {
		y -> left -> parent = x;
	}

	// now change the parent of y to the parent of x
	// to update the y parent to x parent
	y -> parent = x -> parent;

	// if x parent is null that means x is the root
	// so make y as root
	if (NULL == x -> parent) {
		root = y;
	} else if (x == x -> parent -> left) {
		// if x is the left child of parent
		// make y as a left child of parent
		x -> parent -> left = y;
	} else {
		// if x is the right child of parent
		// make y as a right child of parent
		x -> parent -> right = y;
	}

	// make y node the parent of x node
	y -> left = x;
	x -> parent = y;
}

Node* rightRotate(Node* root, Node* x) {
	// got the reference of x left child
	// which is y
	y = x -> left;

	// move y right child to x left child
	x -> left = y -> right;

	// since we moved the y node's right child to x node's left
	// If y right child is not equal to null then 
	// we need to update the parent of the child from y to x;
	if (NULL != y -> right) {
		y -> right -> parent = x;
	}

	// now change the parent of y to the parent of x
	// to update the y parent to x parent
	y -> parent = x -> parent;

	// if x parent is null that means x is the root
	// so make y as root
	if (NULL == x -> parent) {
		root = y;
	} else if (x == x -> parent -> right) {
		// if x is the right child of parent
		// make y as a right child of parent
		x -> parent -> right = y;
	} else {
		// if x is the left child of parent
		// make y as a left child of parent
		x -> parent -> left = y;
	}

	// make y node the parent of x node
	y -> right = x;
	x -> parent = y;
}

Node* insertFix(Node* root) {

}

Node* insert(Node* root, int value) {
	root = insertNode(root, value);
	root = insertFix(root);

	return root;
}


int main(int argc, char const *argv[])
{
	Node* root = NULL;

	return 0;
}