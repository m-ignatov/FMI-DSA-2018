#include <iostream>
#include <queue>
#include <iomanip>

const int MAXN = 131073;
const int MAXN_HALF = 65536;

struct Node
{
	int data;
	Node *leftNode;
	Node *rightNode;

	Node(int d)
	{
		data = d;
		leftNode = NULL;
		rightNode = NULL;
	}
};

std::queue<Node*> q;

class BSTtree
{
public:
	Node* insert(Node* node, int data)
	{
		if (node == NULL) return new Node(data);

		if (data < node->data)
		{
			node->leftNode = insert(node->leftNode, data);
		}
		else
		{
			node->rightNode = insert(node->rightNode, data);
		}

		return node;
	}

	void average(Node *root)
	{
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			long long sum = 0;
			double br = 0;

			while (size)
			{
				Node* cur = q.front();
				q.pop();
				sum += cur->data;
				br++;

				if (cur->leftNode != NULL)
				{
					q.push(cur->leftNode);
				}
				if (cur->rightNode != NULL)
				{
					q.push(cur->rightNode);
				}
				size--;
			}
			if (br)
			{
				std::cout << std::fixed << std::setprecision(2) << (sum / br) << std::endl;
			}
		}
	}
};

int main()
{
	BSTtree bstTree;
	Node* root = NULL;

	int input;
	int data;

	std::cin >> input;
	for (size_t i = 0; i < input; i++)
	{
		std::cin >> data;
		root = bstTree.insert(root, data);
	}
	bstTree.average(root);
}