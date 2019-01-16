#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int MAXN = 200001;
const int MAXT = 10;
const long long MAXLONG = (1L << 63) - 1;
int vertices, edges, start, t;
bool used[MAXN];
long long dist[MAXN];

struct Node
{
	int next;
	int w;
	Node(int _next, int _w) : next(_next), w(_w) {}
};


bool operator< (const Node& lhs, const Node& rhs)
{
	return lhs.w > rhs.w;
}

std::vector<Node> nodes[MAXN];
std::vector<long long> res[MAXT];

void init()
{
	memset(used, false, MAXN);
	for (size_t i = 0; i < MAXN; i++)
	{
		dist[i] = MAXLONG;
	}
}

void clear()
{
	for (size_t i = 0; i < MAXN; i++)
	{
		if (nodes[i].size() > 0) nodes[i].clear();
	}
}

std::vector<long long> diikjstra()
{
	init();
	std::priority_queue<Node> pq;
	dist[start] = 0;
	pq.push(Node(start, 0));

	while (!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();

		int nextV = cur.next;

		if (used[nextV]) continue;
		used[nextV] = true;

		for (int i = 0; i < nodes[nextV].size(); i++)
		{
			Node neighbour = nodes[nextV][i];
			long long sum = (long long)(dist[nextV] + neighbour.w);
			if (sum < dist[neighbour.next])
			{
				dist[neighbour.next] = sum;
				neighbour.w = sum;
				pq.push(neighbour);
			}
		}
	}

	std::vector<long long> res;

	for (int i = 1; i <= vertices; i++)
	{
		if (i == start) continue;
		if (dist[i] != MAXLONG) res.push_back(dist[i]);
		else res.push_back(-1);
	}

	clear();
	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> t;
	for (size_t test = 0; test < t; test++)
	{
		std::cin >> vertices >> edges;
		int beg, end, w;
		for (int i = 1; i <= edges; i++)
		{
			std::cin >> beg >> end >> w;
			nodes[beg].push_back(Node(end, w));
			nodes[end].push_back(Node(beg, w));
		}
		std::cin >> start;

		res[test] = diikjstra();
	}

	for (size_t i = 0; i < t; i++)
	{
		for (size_t j = 0; j < res[i].size(); j++)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << '\n';
	}
	
}
