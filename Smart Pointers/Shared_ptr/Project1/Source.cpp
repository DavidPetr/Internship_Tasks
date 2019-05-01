#include <iostream>
#include <memory>

class Matrix {
private:
	int n_;
	int m_;
public:
	int** operator()(int n, int m)
	{
		n_ = n;
		m_ = m;
		int** matrix;
			matrix = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			matrix[i] = new int[m]();
		}
		return matrix;
	}
	void operator()(int** matrix)
	{
		for (int i = 0; i < n_; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		std::cout << "Functor Deleter Call" << std::endl;
		getchar();
	}
};

int main(int argc, char *argv[])
{

	int n = 10, m = 10;
	std::shared_ptr<int*> shPtr{ Matrix()(n,m), Matrix()};
	
	std::cout << shPtr.use_count() << " " << (*shPtr)[8] << std::endl;
	return 0;
}