#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
	int height;
	double value;
	Node *left;
	Node *right;

	Node(double value)
	{
		this->value = value;
		this->height = 1;
	}

	Node(double value, Node *left, Node *right) : Node(value)
	{
		this->left = left;
		this->right = right;
	}
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node* node, double value)
	{
		if (node == NULL)
		{
			return false;
		}

		if (node->value == value)
		{
			return true;
		}

		if (value < node->value)
		{
			return containsRecursive(node->left, value);
		}
		else
		{
			return containsRecursive(node->right, value);
		}
	}

	void printRecursive(Node* node)
	{
		if (node == NULL)
		{
			return;
		}

		printRecursive(node->left);
		cout << node->value << " ";
		printRecursive(node->right);
	}

	Node* rightRotate(Node* y)
	{
		Node* x = y->left;
		Node* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		return x;
	}

	Node* leftRotate(Node* x)
	{
		Node* y = x->right;
		Node* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getBalance(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return height(node->left) - height(node->right);
	}

	Node* insert(Node* root, double value)
	{
		if (root == NULL)
		{
			return new Node(value);
		}

		if (value < root->value)
		{
			root->left = insert(root->left, value);
		}
		else if (value > root->value)
		{
			root->right = insert(root->right, value);
		}
		else
		{
			std::cout << value << " already added" << '\n';
			return root;
		};

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);

		if (balance > 1 && value < root->left->value)
		{
			return rightRotate(root);
		}

		if (balance < -1 && value > root->right->value)
		{
			return leftRotate(root);
		}

		if (balance > 1 && value > root->left->value)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && value < root->right->value)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node* minValueNode(Node* node)
	{
		Node* current = node;

		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}

	Node* remove(Node* root, double value)
	{
		if (root == NULL)
		{
			std::cout << value << " not found to remove" << '\n';
			return NULL;
		}

		if (value < root->value)
		{
			root->left = remove(root->left, value);
		}
		else if (value > root->value)
		{
			root->right = remove(root->right, value);
		}
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				Node* node = root->left ? root->left : root->right;

				if (node == NULL)
				{
					node = root;
					root = NULL;
				}
				else *root = *node;
				free(node);
			}
			else
			{
				Node* temp = minValueNode(root->right);
				root->value = temp->value;
				root->right = remove(root->right, temp->value);
			}
		}

		if (root == NULL)
		{
			return root;
		}
		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);
		if (balance > 1 && getBalance(root->left) >= 0)
		{
			return rightRotate(root);
		}

		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
		{
			return leftRotate(root);
		}

		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	int height(Node* N)
	{
		if (N == NULL) return 0;
		return N->height;
	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}

	void add(double x)
	{
		root = insert(root, x);
	}

	void remove(double x)
	{
		root = remove(root, x);
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;

		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}
}