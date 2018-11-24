#include <iostream>

struct Node
{
	long long data;
	Node* next;

	Node() : data(0), next(NULL) {}
	Node(long long _data) : data(_data), next(NULL) {}
};

long long peek[10][2] =
{
	{2,-1},{3,-1},{0,4},{1,5},{2,6},{3,7},{4,8},{5,9},{6,-1},{7,-1}
};

int main()
{
	bool flag = false;
	long long n;
	std::cin >> n;

	Node* begin = new Node(1);
	Node* scan = begin;
	std::cout << begin->data << " ";

	Node* node = NULL;
	for (size_t i = 2; i <= 9 && i <= n; i++)
	{
		node = new Node(i);
		scan->next = node;
		scan = node;
		std::cout << node->data << " ";
	}
	if (node != NULL) node->next = begin;

	scan = begin;
	while (1)
	{
		if (flag)
		{
			scan = scan->next;
			flag = false;
		}

		long long scanData = scan->data;
		int lastDigit = scanData % 10;

		scan->data = (scanData * 10 + peek[lastDigit][0]);
		if (scan->data > n) break;
		std::cout << scan->data << " ";

		if (peek[lastDigit][1] != -1)
		{
			flag = true;

			Node* node = new Node(scanData * 10 + peek[lastDigit][1]);
			if (scan->data > n) break;
			std::cout << node->data << " ";

			Node* nextNode = scan->next;
			scan->next = node;
			node->next = nextNode;
		}
		scan = scan->next;
	}
}