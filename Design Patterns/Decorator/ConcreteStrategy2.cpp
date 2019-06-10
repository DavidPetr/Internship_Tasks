#include "ConcreteStrategy2.h"

MergeSort::MergeSort(std::vector<int> vector) : Strategy(vector)
{}

void MergeSort::sort(std::vector<int>& vector)
{
	std::cout << "MergeSort" << std::endl;

	mergeSort(vector, 0, vector.size() - 1);
}

void MergeSort::merge(std::vector<int>& vector, int leftIndex, int middleIndex, int rightIndex)
{
	int i, j, k;
	int sizeOfFirstSequence = middleIndex - leftIndex + 1;
	int sizeOfSecondSequence = rightIndex - middleIndex;

	std::vector<int> L, R;

	for (i = 0; i < sizeOfFirstSequence; i++)
	{
		L.push_back(vector[leftIndex + i]);
	}
	for (j = 0; j < sizeOfSecondSequence; j++)
	{
		R.push_back(vector[middleIndex + 1 + j]);
	}

	i = 0; 
	j = 0; 
	k = leftIndex;

	while (i < sizeOfFirstSequence && j < sizeOfSecondSequence)
	{
		if (L[i] > R[j])
		{
			vector[k] = L[i];
			++i;
		}
		else
		{
			vector[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < sizeOfFirstSequence)
	{
		vector[k] = L[i];
		++i;
		++k;
	}

	while (j < sizeOfSecondSequence)
	{
		vector[k] = R[j];
		++j;
		++k;
	}
}


void MergeSort::mergeSort(std::vector<int>& vector, int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;

		mergeSort(vector, leftIndex, middleIndex);
		mergeSort(vector, middleIndex + 1, rightIndex);

		merge(vector, leftIndex, middleIndex, rightIndex);
	}
}

