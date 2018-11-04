#include<iostream>

const int MAXT = 1001;
int res[MAXT];

int solve()
{
    int n;
    std::cin >> n;

    int i = 0;
    for (i; n >= 1; n >>= 1, i++);
    return i;
}

int main()
{
    int t;
    std::cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        res[i] = solve();
    }

    for (size_t i = 0; i < t; i++)
    {
        std::cout << res[i] << '\n';
    }
}