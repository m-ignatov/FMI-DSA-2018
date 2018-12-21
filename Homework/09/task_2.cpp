#include <iostream>
#include <string>
#include <vector>
#include <map>

const int WORD_MAX_SIZE = 11;
std::map<std::string, int> m;
std::vector<std::pair<std::string, int>> output;

void append(char*& str, const char& c, int pos)
{
	str[pos] = c;
	str[pos + 1] = '\0';
}

void checkEnd(const char* prefixAccum, int i, int l, bool doesExists)
{
	if (!doesExists)
	{
		if (i != l - 1)
		{
			m[prefixAccum] = 0;
		}
		else
		{
			m[prefixAccum] = 1;
		}
	}
	else m[prefixAccum]++;
}

void computeHashes(const std::string& s)
{
	char* prefixAccum = new char[WORD_MAX_SIZE];
	int l = s.size();
	bool flag = false;

	for (size_t i = 0; i < l; i++)
	{
		append(prefixAccum, s[i], i);

		if (m.find(prefixAccum) == m.end())
		{
			checkEnd(prefixAccum, i, l, false);
			if (!flag)
			{
				output.push_back(std::make_pair(prefixAccum, m[prefixAccum]));
				flag = true;
			}
		}
		else if (i == l - 1)
		{
			checkEnd(prefixAccum, i, l, true);
			output.push_back(std::make_pair(prefixAccum, m[prefixAccum]));
		}
	}
	delete[] prefixAccum;
}

int main()
{
	std::string input;
	int n;

	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> input;
		computeHashes(input);
	}

	for (size_t i = 0; i < output.size(); i++)
	{
		std::cout << output[i].first;
		if (output[i].second > 1)
		{
			std::cout << ' ' << output[i].second;
		}
		std::cout << '\n';
	}
}