#include "ConcreteStrategy3.h"


QuickSort::QuickSort(std::vector<int> vector) : Strategy(vector)
{}

void QuickSort::sort(std::vector<int>& vector)
{
	std::cout << "Quick" << std::endl;
	quick(vector, 0, vector.size() - 1);
}

void QuickSort::quick(std::vector<int>& vector, int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(vector, low, high);

		quick(vector, low, pi - 1);  // Before pi
		quick(vector, pi + 1, high); // After pi
	}
}

int QuickSort::partition(std::vector<int>& vector, int low, int high)
{
	int pivot = vector[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (vector[j] >= pivot)
		{
			i++;    // increment index of smaller element 
			swap(vector[i], vector[j]);
		}
	}
	swap(vector[i + 1], vector[high]);
	return (i + 1);
}