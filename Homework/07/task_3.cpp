#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int MAXN = 100001;
int n, m, br = 0, maxNode = -1;
bool used[MAXN];
int cntCoffee[MAXN];

std::vector<int> Nodes[MAXN];

void input()
{
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int cafe;
		std::cin >> cafe;
		cntCoffee[i] = cafe;
	}

	int begin, end;

	for (size_t i = 0; i < n - 1; i++)
	{
		std::cin >> begin >> end;

		begin--;
		end--;

		if (maxNode < begin) maxNode = begin;
		if (maxNode < end) maxNode = end;

		Nodes[begin].push_back(end);
		Nodes[end].push_back(begin);
	}
}

void traverse(int ind)
{
	std::queue<int> q;
	q.push(ind);
	used[ind] = true;

	while (!q.empty())
	{
		int curInd = q.front();
		q.pop();

		if (curInd != 0 && Nodes[curInd].size() == 1 && cntCoffee[curInd] <= m) br++;

		for (int i = 0; i < Nodes[curInd].size(); i++)
		{
			int curIndNext = Nodes[curInd][i];

			if (!used[curIndNext])
			{
				if (!cntCoffee[curIndNext])
				{
					q.push(curIndNext);
				}
				else
				{
					cntCoffee[curIndNext] += cntCoffee[curInd];
					if (cntCoffee[curIndNext] <= m)
					{
						q.push(curIndNext);
					}
				}
				used[curInd] = true;
			}
		}
	}
}

int main()
{
	input();
	traverse(0);
	std::cout << br << '\n';
}