#include "Strategy.h"

Strategy::Strategy(std::vector<int> v) : m_vector(v)
{}

void Strategy::print()
{
	sort(m_vector);

	int space = static_cast<int>(std::log2(m_vector.size()));
	
	int current = space;

	for (int i = 0; i < m_vector.size(); ++i)
	{		
		std::cout << std::setw(current * 2) << m_vector[i] << " ";

		if (i + 1 == static_cast<int>(pow(2, static_cast<int>(log2(i + 1)) + 1) - 1))
		{
			std::cout << std::endl;
			--current;
		}
	}
	std::cout << std::endl << std::endl;
}

void Strategy::swap(int & a, int & b) noexcept
{
	if (a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
}
