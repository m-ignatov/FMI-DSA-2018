#include <iostream>
#include <algorithm>

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

void insertSort(int arr[], int length)
{
	for (size_t i = 1; i < length; i++)
	{
		for (size_t j = i; j >= 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				std::swap(arr[j - 1], arr[j]);
			}
			else break;
		}
	}
}

int main()
{
	print();
	insertSort(arr, size);
	print();
}