#include <iostream>
#include <stack>
#include <string>

struct Node
{
	Node() : data(0), next(NULL) {}
	Node(int n) : data(n), next(NULL) {}
	int data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList() : size(0), head(NULL), tail(NULL) {}

	void add(int val, int pos)
	{
		Node* node = new Node();
		if (pos < 0 || pos > size)
		{
			if (head == NULL)
			{
				node->data = val;
				head = node;
				tail = node;
			}
			else
			{
				node = tail;
				tail = new Node(val);
				node->next = tail;
			}
			std::cout << "add_last";
		}
		else
		{
			node->data = val;

			Node* prev = NULL;
			Node* cur = head;
			for (size_t i = 0; i < pos; i++)
			{
				prev = cur;
				cur = cur->next;
			}
			if (prev != NULL) prev->next = node;
			else head = node;

			node->next = cur;
			if (cur == NULL) tail = node;
		}
		size++;
	}

	void print()
	{
		Node* scan = head;
		while (scan != NULL)
		{
			std::cout << scan->data << "#";
			scan = scan->next;
		}
	}

	void remove(int pos)
	{
		if (pos < 0 || pos + 1 > size)
		{
			std::cout << "remove_failed";
		}
		else
		{
			Node* prev = NULL;
			Node* cur = head;
			for (size_t i = 0; i < pos; i++)
			{
				prev = cur;
				cur = cur->next;
			}
			if (cur != NULL)
			{
				if (prev != NULL)
					prev->next = cur->next;
				else
				{
					head = cur->next;
				}
			}
			else
			{
				tail = prev;
				prev->next = NULL;
			}

			delete cur;
			size--;
		}
	}

	void reverse()
	{
		Node* saveHead = head;

		Node* prev = NULL;
		Node* cur = head;
		Node* next = NULL;

		while (cur != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
		tail = saveHead;
	}

	void remove_all(int val)
	{
		Node* prev = NULL;
		Node* scan = head;

		while (scan != NULL)
		{
			bool flag = false;
			if (scan->data == val)
			{
				if (prev != NULL)
				{
					prev->next = scan->next;
					if (prev->next == NULL) tail = prev;
					flag = true;
				}
				else
				{
					head = scan->next;
					flag = true;
				}
			}

			if (flag)
			{
				Node* save = scan->next;
				delete scan;
				scan = save;
			}
			else
			{
				prev = scan;
				scan = scan->next;
			}
		}
	}

	void group(int a, int b)
	{
		if (a >= size || b >= size || a < 0 || b < 0 || a > b)
		{
			std::cout << "fail_grouping";
		}
		else
		{
			Node* prev = NULL;
			Node* scan = head;
			for (size_t i = 0; i < a; i++)
			{
				prev = scan;
				scan = scan->next;
			}
			Node* cur = scan;
			int sum = 0;

			for (size_t i = a; i <= b; i++)
			{
				sum += cur->data;
				size--;
				if (cur != NULL) cur = cur->next;
				else break;
			}
			Node* newNode = new Node(sum);
			if (prev != NULL) prev->next = newNode;
			else
			{
				head = newNode;
			}

			if (cur != NULL)
				newNode->next = cur;
			else
			{
				newNode->next = NULL;
				tail = newNode;
			}
		}
	}

	void count(int val)
	{
		int cnt = 0;
		Node* scan = head;
		while (scan != NULL)
		{
			if (scan->data == val) cnt++;
			scan = scan->next;
		}
		std::cout << cnt;
	}

	void is_palindrome()
	{
		std::stack<int> st;

		Node* scan = head;
		while (scan != NULL)
		{
			st.push(scan->data);
			scan = scan->next;
		}

		scan = head;
		while (!st.empty())
		{
			if (st.top() != scan->data)
			{
				std::cout << "false";
				return;
			}
			scan = scan->next;
			st.pop();
		}
		std::cout << "true";
	}

	~LinkedList()
	{
		Node* scan = head;
		while (scan != NULL)
		{
			Node* next = scan->next;
			delete scan;
			scan = next;
		}
	}

private:
	Node* head;
	Node* tail;
	int size;
};

int main()
{
	int cases;
	std::cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		LinkedList ll;

		int ops;
		std::string op;
		std::cin >> ops;

		for (int j = 0; j < ops; j++)
		{
			std::cin >> op;

			if (op == "count")
			{
				int arg1;
				std::cin >> arg1;
				ll.count(arg1);
			}

			if (op == "add")
			{
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.add(arg1, arg2);
			}

			if (op == "print")
			{
				ll.print();
			}

			if (op == "remove")
			{
				int arg1;
				std::cin >> arg1;
				ll.remove(arg1);
			}

			if (op == "reverse")
			{
				ll.reverse();
			}

			if (op == "remove_all")
			{
				int arg1;
				std::cin >> arg1;
				ll.remove_all(arg1);
			}

			if (op == "group")
			{
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.group(arg1, arg2);
			}

			if (op == "is_palindrom")
			{
				ll.is_palindrome();
			}
		}
		std::cout << '\n';
	}
}