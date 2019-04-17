#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

bool isPrime(int x)
{
	if (x < 2)return false;
	if (x == 2)return true;
	if ((x & 1) == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
	{
		if (x%i == 0)return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	std::vector<int> V1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> V2 = { 10,10,5,5,3,10,8,0,0,0 };
	std::vector<int> V3;

	/* Task 1
	* Copy all odd numbers from V1 to V3
	*/
	//std::copy_if(V1.begin(), V1.end(), std::back_inserter(V3), [](int i) {return (i & 1) == 1; });


	/* Task 2
	* Copy V1 to V3 in reverse order
	*/
	//std::copy(V1.rbegin(), V1.rend(), std::back_inserter(V3));


	/* Task 3 ???
	* Replace elements from V1 to '$', if element value is 5
	*/
	//auto it = std::find(V1.begin(), V1.end(), 8);
	//std::fill_n(it, V1.end() - it, 0);


	/* Task 4
	* V3[i]=V1[i]+1
	*/
	//std::transform(V1.begin(), V1.end(), std::back_inserter(V3), [](int i) {return i + 1; });


	/* Task 5
	* V3[i]=V1[i]+V2[i]
	*/
	//std::transform(V1.begin(), V1.end(),V2.begin(), std::back_inserter(V3), std::plus<int>());


	/* Task 6
	* Replace elements from V2 to 8, if element value is 5
	*/
	//std::replace(V2.begin(), V2.end(), 5, 8);


	/* Task 7
	* Replace elements from V2 to 4, if element value is prime
	*/
	//std::replace_if(V2.begin(), V2.end(), isPrime, 4);


	/* Task 8
	* Copy V1 to V3 in reverse order, without using std::copy_backward
	*/
	//std::reverse_copy(V1.begin(), V1.end(), std::back_inserter(V3));


	/* Task 9
	* Delete from V2 all repeated neighbors
	*/
	//auto ptr = std::unique(V2.begin(), V2.end(), [](int a, int b) {return a == b; });
	//V2.erase(ptr, V2.end());


	/* Task 10
	* Generate random numbers in V2
	*/
	//std::srand(std::time(nullptr));
	//std::generate(V2.begin(), V2.end(), std::rand);


	/* Task 11 not done
	* Delete from V2 all repeated neighbors, without using std::unique
	*/

	/* New version
	auto it = V2.begin();
	V2.erase(std::remove_if((it = std::adjacent_find(it, V2.end())), V2.end() - 1, [&it](int iter) {  return iter == *(++it); }), V2.end() - 1);
	*/

	/* Old version
	int i = 0;
	auto ptr = V2.begin();
	std::remove_if(V2.begin(), V2.end()-1,
	[V2,&i,&ptr](int a)
	{
	if (a == V2[++i])
	{
	return 1;
	}
	else
	{
	ptr++;
	return 0;
	}
	}
	);
	V2.erase(ptr, V2.end()-1);
	*/

	std::cout << "V1 elements ";
	for (auto i : V1)
	{
		std::cout << i << " ";
	}
	std::cout << "\nV2 elements ";
	for (auto i : V2)
	{
		std::cout << i << " ";
	}
	std::cout << "\nV3 elements ";
	for (auto i : V3)
	{
		std::cout << i << " ";
	}

	getchar();
	return 0;
}
