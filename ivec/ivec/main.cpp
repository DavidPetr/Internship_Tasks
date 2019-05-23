#include "ivec.h"


int main()
{
	ivec v(20, 5);

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << v.size() << " " << v.capacity() << std::endl;

	getchar();
	return 0;
}