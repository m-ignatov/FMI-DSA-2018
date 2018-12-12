#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> data;

int main()
{
	int n, m1, m2;
	std::cin >> m1 >> n;

	data.push_back(m1);

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> m1 >> m2;

		if (std::find(data.begin(), data.end(), m1) != data.end() && std::find(data.begin(), data.end(), m2) == data.end())
		{
			data.push_back(m2);
		}
	}
	std::cout << data.size() << '\n';
}