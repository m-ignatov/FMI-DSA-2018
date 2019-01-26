#include <iostream>
#include <vector>

int arr[] = { 12,124,1,5,299,9 };
int size = sizeof(arr) / sizeof(int);

void print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

void merge(int arr[], int length, int left, int m, int right)
{
	int lenA = m - left + 1;
	int lenB = right - m;
	std::vector<int> a;
	std::vector<int> b;

	for (size_t i = left; i <= m; i++)
	{
		a.push_back(arr[i]);
	}
	for (size_t i = m + 1; i <= right; i++)
	{
		b.push_back(arr[i]);
	}

	int i = 0, j = 0, k = left;
	while (i < lenA & j < lenB)
	{
		if (a[i] < b[j])
		{
			arr[k++] = a[i++];
		}
		else
		{
			arr[k++] = b[j++];
		}
	}
	while (i < lenA)
	{
		arr[k++] = a[i++];
	}
	while (j < lenB)
	{
		arr[k++] = b[j++];
	}
}

void mergeSort(int arr[], int length, int left, int right)
{
	if (left < right)
	{
		int m = (left + right) / 2;
		mergeSort(arr, length, left, m);
		mergeSort(arr, length, m + 1, right);
		merge(arr, length, left, m, right);
	}
}

int main()
{
	print();
	mergeSort(arr, size, 0, size - 1);
	print();
}