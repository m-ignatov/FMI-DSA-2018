#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution
{
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data)
			{
				cur = insert(root->left, data);
				root->left = cur;
			}
			else
			{
				cur = insert(root->right, data);
				root->right = cur;
			}
			return root;
		}
	}

	void topView(Node * root)
	{
		if (root == NULL) return;

		queue<pair<Node*, int>> q;
		map <int, int> m;
		int hd = 0;
		q.push(make_pair(root, hd));

		while (!q.empty())
		{
			pair<Node*, int> curPair = q.front();
			q.pop();

			Node* cur = curPair.first;
			hd = curPair.second;

			if (m.count(hd) == 0)
				m[hd] = cur->data;

			if (cur->left != NULL)
			{
				q.push(make_pair(cur->left, hd - 1));
			}
			if (cur->right != NULL)
			{
				q.push(make_pair(cur->right, hd + 1));
			}
		}

		map <int, int> ::iterator it;
		for (it = m.begin(); it != m.end(); it++)
		{
			std::cout << it->second << " ";
		}
	}
};

int main()
{

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0)
	{
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.topView(root);
}