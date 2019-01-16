#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
const int MAXN = 10000;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
	int dist[MAXN];
	bool used[MAXN];
	memset(used, false, MAXN);
	memset(dist, -1, MAXN);

	vector<int> result;

	queue<int> q;
	q.push(s);

	dist[s] = 0;
	used[s] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < edges[cur].size(); i++)
		{
			int nextV = edges[cur][i];
			if (!used[nextV])
			{
				used[nextV] = true;
				dist[nextV] = dist[cur] + 6;
				q.push(nextV);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (s == i) continue;
		result.push_back(dist[i]);
	}

	return result;
}


int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string nm_temp;
		getline(cin, nm_temp);

		vector<string> nm = split_string(nm_temp);

		int n = stoi(nm[0]);

		int m = stoi(nm[1]);

		vector<vector<int>> edges(MAXN);
		for (int i = 0; i < m; i++)
		{
			int l, r;
			cin >> l >> r;

			edges[l].push_back(r);
			edges[r].push_back(l);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		int s;
		cin >> s;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<int> result = bfs(n, m, edges, s);

		for (int i = 0; i < result.size(); i++) {
			cout << result[i];

			if (i != result.size() - 1) {
				cout << " ";
			}
		}

		cout << "\n";
	}
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
