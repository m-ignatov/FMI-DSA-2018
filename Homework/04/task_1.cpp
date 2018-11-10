#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class List
{
private:
	Node *head, *tail;

public:
	List() : head(NULL), tail(NULL) {}

	void add(int data)
	{
		Node* tmp = new Node();
		tmp->data = data;
		tmp->next = NULL;
		if (this->head == NULL)
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}

	void solve(int& min, int& max, long long& s)
	{
		Node *temp = head;
		while (temp != NULL)
		{
			int data = temp->data;
			if (data > max) max = data;
			if (data < min) min = data;
			s += data;
			temp = temp->next;
		}
	}
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie();

	List list;
	int n;
	
	while (std::cin >> n)
	{
		list.add(n);
	}

	int max = -1, min = 10001;
	long long sum = 0;
	list.solve(min, max, sum);
	std::cout << min << " " << max << " " << sum << '\n';
}