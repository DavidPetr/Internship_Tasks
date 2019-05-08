#include <iostream>
template <typename T>
class ModernClass
{
private:
	T* ptr;
public:
	ModernClass();
	ModernClass(const T& value = 0);
	ModernClass(const ModernClass& obj);
	ModernClass(ModernClass&& obj);
	ModernClass& operator=(const ModernClass& obj);
	ModernClass& operator=(ModernClass&& obj);
	void print();
	~ModernClass();
};

template<typename T>
ModernClass<T>::ModernClass()
{
	this->ptr = nullptr;
}

template<typename T>
ModernClass<T>::ModernClass(const T& value = 0)
{
	this->ptr = new T(value);
}

template<typename T>
ModernClass<T>::ModernClass(const ModernClass& obj)
{
	std::cout << "Copy constructor" << std::endl;
	this->ptr = new T(*(obj.ptr));
}

template<typename T>
ModernClass<T>::ModernClass(ModernClass&& obj)
{
	std::cout << "Move constructor" << std::endl;
	this->ptr = obj.ptr;
	obj.ptr = nullptr;
}


template<typename T>
ModernClass<T>& ModernClass<T>::operator=(const ModernClass& obj)
{
	std::cout << "Copy assignement" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	else
	{
		delete this->ptr;	//placement new will be more comfortable
		this->ptr = new T(*(obj.ptr));
		return *this;
	}
}

template<typename T>
ModernClass<T> & ModernClass<T>::operator=(ModernClass && obj)
{
	std::cout << "Move assignement" << std::endl;
	this->ptr = obj.ptr;
	obj.ptr = nullptr;
	return *this;
}

template<typename T>
void ModernClass<T>::print()
{
	std::cout << *(this->ptr) << std::endl;
}

template<typename T>
ModernClass<T>::~ModernClass()
{
	delete this->ptr;
}


int main()
{
	ModernClass<int> M(5);
	ModernClass<int> P(4);
	ModernClass<int> L(std::move(P));
	ModernClass<int> G(M);
	L.print();
	L = std::move(M);
	L.print();
	L = G;
	L.print();
	getchar();
	return 0;
}