#include "ConcreteStrategy1.h"

BubleSort::BubleSort(std::vector<int> vector) : Strategy(vector)
{}

void BubleSort::sort(std::vector<int>& vector)
{
	std::cout << "Buble" << std::endl;

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
