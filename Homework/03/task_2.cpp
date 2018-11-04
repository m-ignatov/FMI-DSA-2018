#include <iostream>
#include <algorithm>
#include <cmath>

const int MAXN = 100000;
const int MAXQ = 100000;
long long arr[MAXN];
int q, n;

struct Pair
{
    int min, max;

    Pair() : min(-1), max(-1) {}
    Pair(int _min, int _max) : min(_min), max(_max) {}
} res[MAXQ];

void binarySearch(Pair& res, long long* arr, long long p, int left, int right)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == p)
        {
            res.min = mid + 1;
            res.max = mid + 1;
            int i = mid - 1, j = mid + 1;

            while (i >= 0 && arr[i] == p)
            {
                res.min = i + 1;
                i--;
            }
            while (j < n && arr[j] == p)
            {
                res.max = j + 1;
                j++;
            }
        }
        else if (arr[mid] > p) binarySearch(res, arr, p, left, mid - 1);
        else binarySearch(res, arr, p, mid + 1, right);
    }
}

Pair solve()
{
    long long p;
    std::cin >> p;

    if (!(p >= arr[0] && p <= arr[n - 1])) return Pair();
    Pair res;
    binarySearch(res, arr, p, 0, n - 1);
    return res;
}

int main()
{
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr+n);

    std::cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        res[i] = solve();
    }

    for (size_t i = 0; i < q; i++)
    {
        std::cout << res[i].min << " " << res[i].max << '\n';
    }
}