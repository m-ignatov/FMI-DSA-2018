#include <iostream>

const int MAXN = 100001;
int n, k;
long long arr[MAXN];

bool check(long long ans)
{
    long long usedBlows = ans;
    for (size_t i = 0; i < n; i++)
    {
        long long diff = arr[i] - ans;
        if (diff > 0)
        {
            long long neededBlows = diff / (k - 1);
            if (diff % (k - 1) != 0) neededBlows++;

            if (usedBlows < neededBlows) return false;
            else usedBlows -= neededBlows;
        }
    }
    return true;
}

int binarySeach(long long* arr, int l, int r)
{
    long long ans = -1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (check(m))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return ans;
}

int main()
{
    long long maxVal = -1, zeroCnt = 0;
    std::cin >> n >> k;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] == 0) zeroCnt++;
    }

    if (zeroCnt == n) std::cout << 0 << '\n';
    else if (k == 1) std::cout << maxVal << '\n';
    else std::cout << binarySeach(arr, 0, maxVal) << '\n';
}