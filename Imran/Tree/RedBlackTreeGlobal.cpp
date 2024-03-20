/*
	Not working 

	Problem with recursive insert
*/

#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node
{
	int data;
	Node* parent;
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

Node* root;

void leftRotate(Node* node) {
	// getting the node -> parent
	Node* parent = node -> parent;

	// got the reference of node -> right child
	Node* rightChild = node -> right;

	// move rightChild -> left child to node right child
	node -> right = rightChild -> left;

	// since we moved the rightChild -> left child to node -> right
	// If rightChild -> left child is not equal to null then 
	// we need to update the parent of the child from rightChild to node;
	if (NULL != rightChild -> left) {
		rightChild -> left -> parent = node;
	}

	// now change the parent of rightChild to the parent of node
	// to update the rightChild parent to node -> parent
	rightChild -> parent = node -> parent;

	// if node parent is null that means node is the root
	// so make rightChild as root
	if (NULL == node -> parent) {
		root = rightChild;
	} else if (node == node -> parent -> left) {
		// if node is the left child of parent
		// make rightChild as a left child of parent
		node -> parent -> left = rightChild;
	} else {
		// if node is the right child of parent
		// make rightChild as a right child of parent
		node -> parent -> right = rightChild;
	}

	// make rightChild node the parent of node
	rightChild -> left = node;
	node -> parent = rightChild;
}

void rightRotate(Node* node) {
	// getting the node -> parent
	// Node* parent = node -> parent;

	// got the reference of node -> left child
	Node* leftChild = node -> left;

	// move leftChild -> right child to node -> left child
	node -> left = leftChild -> right;

	// since we moved the leftChild -> right child to node -> left
	// If leftChild -> right child is not equal to null then 
	// we need to update the parent of the child from leftChild to node;
	if (NULL != leftChild -> right) {
		leftChild -> right -> parent = node;
	}

	// now change the parent of leftChild to the parent of node
	// to update the leftChild parent to node -> parent
	leftChild -> parent = node -> parent;

	// if node parent is null that means node is the root
	// so make leftChild as root
	if (NULL == node -> parent) {
		root = leftChild;
	} else if (node == node -> parent -> right) {
		// if node is the right child of parent
		// make leftChild as a right child of parent
		node -> parent -> right = leftChild;
	} else {
		// if node is the left child of parent
		// make leftChild as a left child of parent
		node -> parent -> left = leftChild;
	}

	// make leftChild node the parent of node
	leftChild -> right = node;
	node -> parent = leftChild;
}

Node* getUncle(Node* parent) {
	Node* grandparent = parent -> parent;

	if (grandparent -> left == parent) {
		return grandparent -> right;
	} else if (grandparent -> right == parent) {
		return grandparent -> left;
	}

	return NULL;
}

void insertFix(Node* node) {
	Node* parent = node -> parent;

	// Case 1: 
	// Parent is null, we've reached the root, 
	// the end of the recursion
	if (NULL == parent) {
		node -> color = BLACK;
		return;
	}

	// Parent is black --> nothing to do
	if (BLACK == parent -> color) {
		return;
	}

	// From here on, parent is red
	Node* grandparent = parent -> parent;

	// case 2:
	// Not having a grandparent means that parent is the root. 
	// If we enforce black roots (rule 2)
	// If the grandparent will never be null, 
	// then the following if-then block can be removed.

	if (NULL == grandparent) {
		parent -> color = BLACK;
		return;
	}

	// From here on, there will be grandparent
	// Get the uncle (may be null/nil, in which case its color is BLACK)
	Node* uncle = getUncle(parent);

	// Case 3: Uncle is red -> recolor parent, grandparent and uncle
	if (NULL != uncle && uncle -> color == RED) {
		parent -> color = BLACK;
		grandparent -> color = RED;
		uncle -> color = BLACK;

		// Call recursively for grandparent, which is now red.
		// It might be root or have a red parent, in which case 
		// we need to fix more
		insertFix(grandparent);
	} else if (grandparent -> left == parent) {
		// Parent is left child of grandparent

		// Case 4a: Uncle is black and node is 
		// left->right "inner child" of its grandparent
		if (parent -> right == node) {
			leftRotate(parent);

			// Let "parent" point to the new root node 
			// of the rotated sub-tree. It will be recolored in
			// the next step, which we're going to fall-through to.
			parent = node;
		}

		// Case 5a:
		// Uncle is black and node is left->left 
		// "outer child" of its grandparent
		rightRotate(grandparent);

		// Recolor original parent and grandparent
		parent -> color = BLACK;
		grandparent -> color = RED;
	} else {
		// Parent is right child of grandparent
		
		// Case 4b:
		// Uncle is black and node is right->left
		// "inner child" of its grandparent
		if (parent -> left == node) {
			rightRotate(parent);

			// Let "parent" point to the new root node 
			// of the rotated sub-tree. It will be recolored
			// in the next step, which we're going to fall-through to.
			parent = node;
		}

		// Case 5b:
		// Uncle is black and node is right->right
		// "outer child" of its grandparent
		leftRotate(grandparent);

		// Recolor original parent and grandparent
		parent -> color = BLACK;
		grandparent -> color = RED;
	}
}

Node* insertNode(Node* root, Node* newNode) 
{
	if (NULL == root) {
		// creating new node and assign it to root
		root = newNode; // creating new node with value
		return root;
	}

	if (newNode -> data < root -> data) {
		root -> left = insertNode(root -> left, newNode);
	} else {
		root -> right = insertNode(root -> right, newNode);
	}

	return root;
}

Node* insert(Node* root, int value) {
	// creating new node
	Node* newNode = new Node(value);

	// passing the root and newNode
	root = insertNode(root, newNode);
	insertFix(newNode);

	return root;
}

void preOrder(Node* root)
{
	if(NULL == root)
	{
		return;
	}

	cout << root -> data << endl;
	preOrder(root -> left);
	preOrder(root -> right);
}

void printHelper(Node* travel, string indent, bool last) {
	if (travel != NULL) {
		cout << indent;
		
		if (last) {
			cout << "R----";
			indent += "   ";
		} else {
			cout << "L----";
			indent += "|  ";
		}

		string sColor = travel -> color == RED ? "RED" : "BLACK";

		cout << travel->data << "(" << sColor << ")" << endl;
		printHelper(travel -> left, indent, false);
		printHelper(travel -> right, indent, true);
	}
}

void printTree() 
{
	if (root) {
		printHelper(root, "", true);
	}
}

int main(int argc, char const *argv[])
{
	root = NULL;

	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 9);

	preOrder(root);

	cout << endl << endl;

	printTree();

	return 0;
}