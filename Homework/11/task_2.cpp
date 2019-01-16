#include <iostream>
#include <vector>
#include <limits>

const int MAXN = 1001;
const long long MAX_LONG = std::numeric_limits<long long>::max();
long long dist[MAXN];
int start, end, edges, vertices;

struct Edge
{
	int from;
	int to;
	long long w;

	Edge(int _from, int _to, long long _w) : from(_from), to(_to), w(_w) {}
};

std::vector<Edge> edgesVector;

void input()
{
	int b, e, w;
	std::cin >> vertices >> edges >> start >> end;
	for (size_t i = 0; i < edges; i++)
	{
		std::cin >> b >> e >> w;
		edgesVector.push_back(Edge(b, e, w));
	}
}


void init()
{
	for (size_t i = 1; i <= vertices; i++)
	{
		dist[i] = MAX_LONG;
	}
	dist[start] = 0;

	for (size_t i = 0; i < edges; i++)
	{
		edgesVector[i].w = -edgesVector[i].w;
	}
}

void solve()
{
	for (size_t k = 1; k < vertices; k++)
	{
		for (size_t i = 0; i < edges; i++)
		{
			int from = edgesVector[i].from;
			int to = edgesVector[i].to;
			int w = edgesVector[i].w;

			if (dist[from] != MAX_LONG && dist[from] + w < dist[to])
			{
				dist[to] = dist[from] + w;
			}
		}
	}

	if (dist[end] != MAX_LONG) std::cout << (-dist[end]);
	else std::cout << (-1);
	std::cout << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	input();
	init();
	solve();
}
