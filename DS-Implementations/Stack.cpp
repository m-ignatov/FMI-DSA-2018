#include <iostream>

struct Node
{
	Node() : data(0), next(NULL) {}
	Node(int n) : data(n), next(NULL) {}

	int data;
	Node* next;
};

class Stack
{
public:
	Stack() : size(0), top(NULL) {}

	void push(int arg)
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

	const int peek()
	{
		if (size)
		{
			return top->data;
		}
	}

	int pop()
	{
		if (size <= 0) return -1;

		int res = top->data;
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

int main()
{
	Stack st;
	st.push(1);
	st.push(2);
	std::cout << st.pop() << '\n';
	std::cout << st.pop() << '\n';
	st.push(32);
	std::cout << st.pop() << '\n';
	std::cout << st.pop() << '\n';
}