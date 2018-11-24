#include <iostream>
#include <string>

struct Node
{
	Node() : data(0), next(NULL) {}
	Node(long long n) : data(n), next(NULL) {}

	long long data;
	Node* next;
};

class Stack
{
public:
	Stack() : size(0), top(NULL) {}

	void push(long long arg)
	{
		if (top == NULL)
		{
			Node* node = new Node(arg);
			top = node;
		}
		else
		{
			Node* node = new Node(arg);
			node->next = top;
			top = node;
		}
		size++;
	}

	const int getSize()
	{
		return size;
	}

	const long long peek()
	{
		if (size)
		{
			return top->data;
		}
	}

	Node*& getNodeTop()
	{
		return top;
	}

	long long pop()
	{
		if (size <= 0) return -1;

		long long res = top->data;
		Node* toDelete = top;
		top = top->next;

		delete toDelete;
		size--;

		return res;
	}

	~Stack()
	{
		Node* scan = top;
		while (scan != NULL)
		{
			Node* save = scan->next;
			delete scan;
			scan = save;
		}
	}

private:
	Node* top;
	int size;
};

void reversePrint(Node*& st)
{
	if (st->next == NULL)
	{
		std::cout << st->data << " ";
		return;
	}
	reversePrint(st->next);
	std::cout << st->data << " ";
}

int main()
{
	Stack st;
	int queries;

	std::cin >> queries;
	for (size_t i = 0; i < queries; i++)
	{
		std::string color;
		long long k;
		std::cin >> color >> k;

		if (color == "white")
		{
			st.push(k);
		}
		else if (color == "green")
		{
			long long sum = 0;
			while (k > 0)
			{
				sum += st.pop();
				k--;
			}
			st.push(sum);
		}
		else if (color == "blue")
		{
			long long max = st.pop();
			while (k > 1)
			{
				long long cur = st.pop();
				if (cur > max) max = cur;
				k--;
			}
			st.push(max);
		}
	}
	reversePrint(st.getNodeTop());
}