#include <iostream>

using std::cout;
using std::cin;
using std::string;

class Node
{
public:
	int value;
	Node* next;
	Node* previous;

	Node()
	{ }

	Node(int val, Node* nex, Node* prev) : value(val), next(nex), previous(prev)
	{ }

};

Node* insert(Node* previous, int value)
{
	Node* newNode = new Node();
	newNode->value = value;

	// since we insert at the last element
	// we want the next to be null
	newNode->next = NULL;
	newNode->previous = previous;
	previous->next = newNode;

	return newNode;
}

Node* insertRoot(Node* root, int value)
{
	Node* newRoot = new Node();

	newRoot->value = value;

	newRoot->previous = NULL;
	newRoot->next = root;
	root->previous = newRoot;

	return newRoot;
}

Node* insertBefore(Node* node, int value)
{
	Node* newNode = new Node();

	newNode->value = value;

	// if root
	if(node->previous == NULL)
	{
		return insertRoot(node, value);
	}

	newNode->next = node;
	newNode->previous = node->previous->previous;
	node->previous = newNode;
	return newNode;
}

Node* insertAfter(Node* node, int value)
{
	Node* newNode = new Node();
	newNode->value = value;

	if(node->next == NULL)
	{
		return insert(node, value);
	}

	// insert between previous and previous->next
	newNode->previous = node;
	newNode->next = node->next;
	node->next = newNode;
	node->next->previous = newNode;

	return newNode;
}

Node* getRoot(Node* node)
{
	Node* tmp = node;
	while(tmp->previous != NULL)
	{
		tmp = tmp->previous;
	}
	return tmp;
}

Node* getNthNode(Node* root, int n)
{
	if(n <= 0 || n == 1)
		return root;

	Node* tmp = root;

	while(n > 1)
	{
		tmp = tmp->next;
		n--;
	}

	return tmp;
}

Node* getLastNode(Node* root)
{
	Node* tmp = root;

	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	return tmp;
}


void printAllNodes(Node* node)
{
	cout << '\n';
	if(node->previous == NULL && node->next == NULL)
	{
		cout << node->value;
		return;
	}

	Node* tmp = getRoot(node);

	while(tmp->next != NULL)
	{
		cout << "value:" << tmp->value << '\n';
		tmp = tmp->next;
	}
	cout << "value:" << tmp->value << '\n';
}

int main()
{
	Node* root = new Node(1, NULL, NULL);
	insertAfter(root, 3);
	insertBefore(root, 2);
	insertAfter(root, 1);
	insertRoot(root, 20);
	printAllNodes(root);
	insertRoot(root, 21);
	printAllNodes(root);
}
