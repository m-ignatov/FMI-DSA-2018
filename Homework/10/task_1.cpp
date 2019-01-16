#include <iostream>
#include <queue>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
const int MAXN = 30001;
bool used[MAXN];

int BFS(int startV, vector<vector<int>>& gb)
{
	int verticesCnt = 1;
	queue<int> q;
	q.push(startV);
	used[startV] = true;

	while (!q.empty())
	{
		int curV = q.front();
		q.pop();

		for (int i = 0; i < gb[curV].size(); i++)
		{
			int nextV = gb[curV][i];
			if (!used[nextV])
			{
				q.push(nextV);
				verticesCnt++;
				used[nextV] = true;
			}
		}
	}

	return verticesCnt;
}

vector<int> componentsInGraph(vector<vector<int>> gb)
{
	vector<int> res;
	int minComponentCnt = (1L << 31) - 1;
	int maxComponentCnt = -1;
	bool isTraversed = false;
	int vSize = gb.size();

	while (1)
	{
		int v;

		for (int i = 0; i <= vSize; i++)
		{
			if (i == vSize)
			{
				isTraversed = true;
				break;
			}

			if (gb[i].size() == 0) continue;

			v = gb[i][0];
			if (!used[v]) break;
		}

		if (isTraversed) break;
		int currComponentCnt = BFS(v, gb);

		if (currComponentCnt > maxComponentCnt)
		{
			maxComponentCnt = currComponentCnt;
		}

		if (currComponentCnt < minComponentCnt)
		{
			minComponentCnt = currComponentCnt;
		}
	}

	res.push_back(minComponentCnt);
	res.push_back(maxComponentCnt);

	return res;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> gb(MAXN);

	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		gb[l].push_back(r);
		gb[r].push_back(l);
	}

	vector<int> SPACE = componentsInGraph(gb);

	for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
		cout << SPACE[SPACE_itr];

		if (SPACE_itr != SPACE.size() - 1) {
			cout << " ";
		}
	}
	cout << "\n";
}
