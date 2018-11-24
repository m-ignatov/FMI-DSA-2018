#include<iostream>

struct Node
{
	Node() : n(0), next(NULL) {}
	Node(int _n) : n(_n), next(NULL) {}
	int n;
	Node* next;
};

Node* start = new Node(1);
Node* marker = start;

int main()
{
	int n;
	std::cin >> n;
	for (size_t i = 3; i <= n; i += 2)
	{
		Node* node = new Node(i);
		marker->next = node;
		marker = node;
	}
	marker->next = start;

	Node* scan = start;
	while (1)
	{
		Node* pointer = scan->next;
		scan->next = pointer->next;
		if (scan == scan->next) break;
		scan = scan->next;
	}
	std::cout << scan->n << '\n';
}