
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	// default constructor
	Node() { }

	Node(int value) {
		data = value;
		left = NULL;
		right = NULL;
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

int minValue(Node* root) 
{
	if (NULL == root -> left) {
		return root -> data;
	}

	return minValue(root -> left);
}

int maxValue(Node* root) 
{
	if (NULL == root -> right) {
		return root -> data;
	}

	return maxValue(root -> right);
}

Node* deleteNode(Node* root, int target) 
{
	if (NULL == root) {
		return root;
	}

	if (target > root -> data) {
		root -> right = deleteNode(root -> right, target);
	} else if (target < root -> data) {
		root -> left = deleteNode(root -> left, target);
	} else {
		// find the value, now delete it

		// no children
		if (NULL == root -> left && NULL == root -> right) {
			root = NULL;
		} else if (NULL == root -> left) {
			// only right child
			root = root -> right;
		} else if (NULL == root -> right) {
			// only left child
			root = root -> left;
		} else {
			// both left and right children
			int replaceValue = maxValue(root -> left);
			root -> data = replaceValue;

			root -> left = deleteNode(root -> left, replaceValue);
		}
	}

	return root;
}

bool search(Node* root, int target)
{
	if (NULL == root) {
		return false;
	}

	if (target == root -> data) {
		return true;
	}

	if (target < root -> data) {
		return search(root -> left, target);
	}

	return search(root -> right, target);
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

void inOrder(Node* root) {
	if(NULL == root)
	{
		return;
	}

	inOrder(root -> left);
	cout << root -> data << endl;
	inOrder(root -> right);
}

void postOrder(Node* root) {
	if(NULL == root)
	{
		return;
	}

	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> data << endl;
}

int main(int argc, char const *argv[])
{
	// declaring root with NULL pointer
	Node* root = NULL;

	cout << "How many nodes do you want to enter: ";
	int nodeCount;
	cin >> nodeCount;

	for (int i = 0; i < nodeCount; ++i) {
		int value;
		cout << "enter the node value to enter: ";
		cin >> value;

		// every time we need to update root
		// after insertion and deletion
		root = insertNode(root, value);
	}

	preOrder(root);
	cout << endl;

	deleteNode(root, 1);

	cout << endl;
	preOrder(root);

	return 0;
}