#include <iostream>
#include <queue>
#include <cstring>

const int MAXM = 5000, MAXN = 5000, MAXK = MAXM * MAXN;
int maze[MAXM][MAXN];
int res[MAXK];
bool isVisited[MAXM][MAXN];

int adjR[] = { 0, 0, -1, 1 };
int adjC[] = { 1, -1, 0, 0 };
int m, n, k;

struct Point
{
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	int x, y;
};

struct Node
{
	Node() : p(Point()), dist(0) {}
	Node(Point _p, int _dist) : p(_p), dist(_dist) {}
	Point p;
	int dist;
};

int solve(Point src, Point dest)
{
	if (maze[src.x][src.y] || maze[dest.x][dest.y]) return -1;

	memset(isVisited, false, sizeof(isVisited));

	std::queue<Node> q;
	q.push(Node(src, 0));
	isVisited[src.x][src.y] = true;

	while (!q.empty())
	{
		Node cur = q.front();
		Point curP = cur.p;
		if (curP.x == dest.x && curP.y == dest.y)
		{
			return cur.dist;
		}

		q.pop();

		for (size_t i = 0; i < 4; i++)
		{
			Point adjP = Point(curP.x + adjC[i], curP.y + adjR[i]);
			if (isVisited[adjP.x][adjP.y] == false && maze[adjP.x][adjP.y] == 0)
			{
				q.push(Node(adjP, cur.dist + 1));
				isVisited[adjP.x][adjP.y] = true;
			}
		}
	}
	return -1;
}

void frame()
{
	for (size_t i = 0; i <= m + 1; i++) maze[i][0] = 1;
	for (size_t i = 0; i <= n + 1; i++) maze[0][i] = 1;
	for (size_t i = 0; i <= n + 1; i++) maze[m + 1][i] = 1;
	for (size_t i = 0; i <= m; i++) maze[i][n + 1] = 1;
}

int main()
{
	std::cin >> m >> n >> k;
	frame();

	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			std::cin >> maze[i][j];
		}
	}

	for (size_t i = 0; i < k; i++)
	{
		int x, y;
		std::cin >> x >> y;
		res[i] = solve(Point(1, 1), Point(x + 1, y + 1));
	}

	for (size_t i = 0; i < k; i++)
	{
		std::cout << res[i] << "\n";
	}
}