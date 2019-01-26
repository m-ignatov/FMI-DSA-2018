#include <iostream>

int arr[] = { 12,124,1,5,299,2 };
int size = sizeof(arr) / sizeof(int);

void print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

int partition(int arr[], int length, int leftInd, int rightInd)
{
	int pivot = arr[leftInd];
	int storeInd = leftInd + 1;

	for (size_t i = leftInd + 1; i <= rightInd; i++)
	{
		if (pivot >= arr[i])
		{
			std::swap(arr[storeInd], arr[i]);
			storeInd++;
		}
	}
	std::swap(arr[leftInd], arr[storeInd - 1]);
	return (storeInd - 1);
}

void quickSort(int arr[], int length, int left, int right)
{
	if (left <= right)
	{
		int p = partition(arr, length, left, right);
		quickSort(arr, length, left, p - 1);
		quickSort(arr, length, p + 1, right);
	}
}

int main()
{
	print();
	quickSort(arr, size, 0, size - 1);
	print();
}