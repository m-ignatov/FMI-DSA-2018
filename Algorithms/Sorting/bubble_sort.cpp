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

void bubbleSort(int* arr, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		bool flag = false;

		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				std::swap(arr[j], arr[j + 1]);
			}
		}
		if (!flag) break;
	}
	
}

int main()
{
	print();
	bubbleSort(arr, size);
	print();
}