#include <iostream>

int arr[] = { 5, 1, 6, 9, 2, 3, 4 };
int size = sizeof(arr) / sizeof(int);

void print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

void selectionSort(int* arr, int length)
{
	for (size_t i = length - 1; i > 0; i--)
	{
		int maxInd = i;

		for (size_t j = 0; j < i; j++)
		{
			if (arr[maxInd] < arr[j]) maxInd = j;
		}
		std::swap(arr[maxInd], arr[i]);
	}
}

int main()
{
	print();
	selectionSort(arr, size);
	print();
}