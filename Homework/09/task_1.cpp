#include <iostream>

int br = 0;

struct Node
{
	long long data;
	Node *leftNode;
	Node *rightNode;

	Node(long long d)
	{
		data = d;
		leftNode = NULL;
		rightNode = NULL;
	}
};

class BSTtree
{
public:
	Node* insert(Node* node, long long data)
	{
		if (node == NULL)
		{
			br++;
			return new Node(data);
		}

		if (data < node->data)
		{
			node->leftNode = insert(node->leftNode, data);
		}
		else if (data > node->data)
		{
			node->rightNode = insert(node->rightNode, data);
		}

		return node;
	}
};

int main()
{
	BSTtree bstTree;
	Node* root = NULL;

	int input;
	long long data;

	std::cin >> input;
	for (size_t i = 0; i < input; i++)
	{
		std::cin >> data;
		root = bstTree.insert(root, data);
	}
	std::cout << br << '\n';
}