#include "ivec.h"
#include "ivecUT.h"

int main(int argc, char** argv)
{
	ivec v(2,3);

	
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl<<"Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

	
	ivecUT UT;
	UT.Test();
	
	getchar();
	return 0;
}