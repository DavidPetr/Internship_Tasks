#include "ConcreteStrategy2.h"

MergeSort::MergeSort(const iVec& vector) : Strategy(vector)
{}

void MergeSort::sort(iVec& vector)
{
	std::cout << "MergeSort" << std::endl;

	mergeSort(vector, 0, vector.size() - 1);
}

void MergeSort::merge(iVec& vector, int leftIndex, int middleIndex, int rightIndex)
{
	int i, j, k;
	int sizeOfFirstSequence = middleIndex - leftIndex + 1;
	int sizeOfSecondSequence = rightIndex - middleIndex;

	std::remove_reference<decltype(vector)>::type L, R;

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


void MergeSort::mergeSort(iVec& vector, int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;

		mergeSort(vector, leftIndex, middleIndex);
		mergeSort(vector, middleIndex + 1, rightIndex);

		merge(vector, leftIndex, middleIndex, rightIndex);
	}
}

