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
	Node& operator=(const Node& a);
};

Node& Node::operator=(const Node &a)
{
	if(this != &a)
	{
		this->value = a.value;
	}
	return *this;
}

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
	newNode->previous = node->previous;
	node->previous->next = newNode;
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

void swapNodes(Node* first, Node* second)
{
	std::swap(first->value, second->value);
}

void sortNodesAscending(Node* root, bool includeRoot=false)
{
	Node* tmp =  includeRoot == false ? (root->next) : (root);
	int countNodes = 0;
	while(tmp->next != NULL)
	{
		countNodes++;
		tmp = tmp->next;
	}

	for(int i = 0; i < countNodes; i++)
	{
		tmp = includeRoot == false ? (root->next) : (root);
		while(tmp->next != NULL)
		{
			if(tmp->value > tmp->next->value)
			{
				swapNodes(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}

void sortNodesDescending(Node* root, bool includeRoot = false)
{
	Node* tmp = includeRoot==false?(root->next):(root);

	int countNodes = 0;
	while(tmp->next != NULL)
	{
		countNodes++;
		tmp = tmp->next;
	}

	for(int i = 0; i < countNodes; i++)
	{
		tmp = includeRoot == false ? (root->next) : (root);
		while(tmp->next != NULL)
		{
			if(tmp->value < tmp->next->value)
			{
				swapNodes(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
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
		if(tmp->previous == NULL)
		{
			cout << tmp->value << " = the root\n";
		}
		else
		{
			cout << tmp->value << '\n';
		}
		tmp = tmp->next;
	}
	cout << tmp->value << " = the end\n";
}