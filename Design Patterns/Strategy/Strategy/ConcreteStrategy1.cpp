#include "ConcreteStrategy1.h"

inline int leftSon(int& i)
{
	return (2 * i + 1);
}
inline int rightSon(int& i)
{
	return (2 * (i + 1));
}

HeapSort::HeapSort(const iVec& vector) : Strategy(vector)
{}

void HeapSort::sort(iVec& vector)
{
	std::cout << "HeapSort" << std::endl;
	int vertex_count = vector.size();
	while (vertex_count != 1)
	{
		
		for (int i = (vertex_count / 2) - 1; i >= 0; --i)
		{
			
			if (leftSon(i) < vertex_count &&  vector[i] > vector[leftSon(i)] )
			{
				swap(vector[i], vector[leftSon(i)]);
			}
			if (rightSon(i) < vertex_count && vector[i] > vector[rightSon(i)])
			{
				swap(vector[i], vector[rightSon(i)]);
			}
		}
		swap(vector[0], vector[vertex_count - 1]);

		--vertex_count;
	}
}

