#include "ConcreteStrategy2.h"

MergeSort::MergeSort(std::vector<int> vector) : Strategy(vector)
{}

void MergeSort::sort(std::vector<int>& vector)
{
	std::cout << "Merge" << std::endl;

	for (int i = 0;i < vector.size();++i)
	{
		for (int j = i + 1;j < vector.size();++j)
		{
			if (vector[i] < vector[j])
			{
				swap(vector[i], vector[j]);
			}
		}
	}
}

void MergeSort::merge(std::vector<int> vector, int leftIndex, int rightIndex)
{
	
}


void MergeSort::mergeSort(std::vector<int> vector, int leftIndex, int rightIndex)
{
	
}

