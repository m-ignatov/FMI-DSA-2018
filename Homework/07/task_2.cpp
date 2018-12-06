#include <iostream>
#include <queue>
#include <iomanip>

class MinMaxHeap
{
private:
	std::priority_queue<int> min_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> max_heap;
	double median;

	void balance()
	{
		bool maxBigger = true;
		int diff = max_heap.size() - min_heap.size();
		if (diff < 0)
		{
			diff = -diff;
			maxBigger = false;
		}

		if (diff > 1)
		{
			int extract;
			if (maxBigger)
			{
				extract = max_heap.top();
				max_heap.pop();
				min_heap.push(extract);
			}
			else
			{
				extract = min_heap.top();
				min_heap.pop();
				max_heap.push(extract);
			}
		}
	}

	void setMedian()
	{
		if (min_heap.size() == max_heap.size())
		{
			int sum = min_heap.top() + max_heap.top();
			median =  sum / 2.;
		}
		else if (min_heap.size() > max_heap.size())
		{
			median = min_heap.top();
		}
		else
		{
			median = max_heap.top();
		}
	}

public:
	MinMaxHeap() : median(0) {}

	void insert(const int& n)
	{
		if (isEmpty())
		{
			median = n;
		}

		if (n > median)
		{
			max_heap.push(n);
		}
		else
		{
			min_heap.push(n);
		}

		balance();
		setMedian();
	}

	bool isEmpty()
	{
		return (min_heap.empty() && max_heap.empty());
	}

	double getMedian() const
	{
		return median;
	}
};

int main()
{
	MinMaxHeap heap;
	int input;
	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> input;
		heap.insert(input);
		std::cout << std::fixed << std::setprecision(1) << heap.getMedian() << '\n';
	}
}