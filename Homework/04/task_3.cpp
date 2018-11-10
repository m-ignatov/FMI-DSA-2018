//Greedy algorithm
#include<iostream>
#include<vector>

struct Balls
{
	Balls() : sum(0) {}
	long long sum;
	std::vector<int> balls;
};

const int MAXN = 1000001;
Balls data[MAXN];
int dataSize = 0;

int main()
{
	long long s = 0;
	int n;
	std::cin >> n;
	for (size_t i = 1; i <= n; i++)
	{
		int p, m;
		std::cin >> p >> m;
		if (m > 0)
		{
			data[i].sum = data[p].sum + m;
			s += data[i].sum;
			//std::cout << data[i].sum << " ";
			for (size_t j = 0; j < data[p].balls.size(); j++)
			{
				data[i].balls.push_back(data[p].balls[j]);
			}
			data[i].balls.push_back(m);
		}
		else if (m == 0)
		{
			int lastBallId = data[p].balls.size() - 1;
			int minusSize = data[p].balls[lastBallId];
			data[i].sum = data[p].sum - minusSize;
			s += data[i].sum;
			//std::cout << data[i].sum << " ";
			for (size_t j = 0; j < data[p].balls.size() - 1; j++)
			{
				data[i].balls.push_back(data[p].balls[j]);
			}
		}
	}
	std::cout << s << '\n';
}