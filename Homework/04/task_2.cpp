#include <iostream>

const int MAXP = 1235;
int used[MAXP];

struct Node
{
	int data;
	Node* next;
};

Node* head;

void add(int value)
{
	Node *tmp = new Node();
	tmp->data = value;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
		tmp = NULL;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}


int solve()
{
	int br = 0;
	Node* tmp = head;
	while (tmp != NULL)
	{
		int num1 = tmp->data;
		tmp = tmp->next;

		if (tmp == NULL) break;
		int num2 = tmp->data;

		if (used[num1] != 0 && used[num2] != 0)
			if (used[num1] != num2 && used[num2] != num1)
			{
				used[num1] = num2;
				used[num2] = num1;
				br++;
			}
	}
	return br;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie();

	int n, p;

	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		add(tmp);
	}

	std::cin >> p;
	for (size_t i = 0; i < p; i++)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp > MAXP || tmp < 0) continue;
		used[tmp] = -1;
	}
	std::cout << solve() << '\n';
}