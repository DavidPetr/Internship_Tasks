#include "Strategy.h"

Strategy::Strategy(std::vector<int> v) : m_vector(v)
{}

void Strategy::print()
{
	sort(m_vector);

	for (auto i : m_vector)
		std::cout << i << " ";
	std::cout << std::endl;
}

void Strategy::swap(int & a, int & b)
{
	if (a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
}
