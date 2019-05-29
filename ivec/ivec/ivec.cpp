#include "ivec.h"


int nearest_power_of_two_integer(int x) 
{
	int i;
	for (i = 2; i < x; i *= 2) {}
	return i;
}

ivec::ivec(int size, int value)
{
	if (size == 0)
	{
		this->_capacity = this->_size = 0;
		return;
	}
	else
	{
		this->_capacity = nearest_power_of_two_integer(size);
		this->_vector = new int[this->_capacity];

		while (this->_size < size)
		{
			this->push_back(value);
		}
	}
}

ivec::ivec(const ivec & vec)
{
	if (vec._vector == nullptr)
	{
		this->_vector = nullptr;
		this->_size = 0;
		this->_capacity = 0;
	}
	else
	{
		this->_vector = new int[vec._size];
		this->_size = vec._size;
		for (int i = 0; i < vec._size; ++i)
		{
			this->_vector[i] = vec._vector[i];
		}
		this->_capacity = vec._capacity;
	}
}

ivec & ivec::operator=(const ivec & vec)
{
	if (this == &vec)
	{
		return *this;
	}
	else if (vec._vector == nullptr)
	{
		this->_vector = nullptr;
		this->_size = 0;
		this->_capacity = 0;
	}
	else
	{
		this->clear();
		this->_vector = new int[vec._size];
		this->_size = vec._size;
		for (int i = 0; i < vec._size; ++i)
		{
			this->_vector[i] = vec._vector[i];
		}
		this->_capacity = vec._capacity;
	}
	return *this;
}

void ivec::reserve(int n)
{
	if (n > this->_capacity)
	{
		int capacity = nearest_power_of_two_integer(n);
		int size = this->_size;

		int* vec = new int[capacity];
		for (int i = 0; i < this->_size; ++i)
		{
			vec[i] = this->_vector[i];
		}		
		this->clear();		
		this->_vector = vec;
		this->_size = size;
		this->_capacity = capacity;
	}
}

void ivec::resize(int n, int val)
{
	if (n == 0)
	{
		this->clear();
		return;
	}
	else if (n < this->_size)
	{
		this->_size = n;
		return;
	}
	while (n > this->_size)
	{
		this->push_back(val);
	}
}

void ivec::push_back(int val)
{
	if (this->_size < this->_capacity)
	{
		this->_vector[this->_size] = val;
		++this->_size;
	}
	else
	{
		int current_size = this->_size;
		if (this->_size == 0)
		{
			this->_size = 2;
		}
		int *temp = new int[this->_size * 2];
		
		int i;
		for (i = 0; i < current_size; ++i)
		{
			temp[i] = this->_vector[i];
		}
		temp[i] = val;

		this->clear();
		this->_vector = temp;
		this->_capacity= current_size * 2;
		this->_size = current_size + 1;
	}
}

void ivec::pop_back()
{
	if (this->_size == 0)
	{
		throw std::out_of_range("Trying to pop from empty object!!!");
	}
	if (this->_size == 1)
	{
		return this->clear();
	}
	else
	{
		--this->_size;
	}
}

int & ivec::operator[](int index)
{
	return this->_vector[index];
}

ivec::iterator ivec::begin()
{
	return &this->_vector[0];
}

ivec::iterator ivec::end()
{
	return &this->_vector[this->_size];
}

void ivec::erase(const_iterator c_it)
{
	if (c_it == nullptr)
	{
		throw std::logic_error("Trying erase null const iterator!!!");
	}
	int i;
	for (i = 0; i < this->_size; ++i)
	{
		if (&this->_vector[i] == c_it)
		{
			break;
		}
	}
	for (int j = i; j < this->_size - 1; ++j)
	{
		this->_vector[j] = this->_vector[j + 1];
	}
	--this->_size;
}

void ivec::insert(iterator it, int val)
{
	if (it == nullptr)
	{
		throw std::logic_error("Trying insert null iterator!!!");
	}
	if (it == this->end())
	{
		return this->push_back(val);
	}
	else if (this->_size < this->_capacity)
	{
		int i;
		for (i = this->_size; i > 0; --i)
		{
			this->_vector[i] = this->_vector[i - 1];
			if (&this->_vector[i-1] == it)
			{
				this->_vector[i - 1] = val;
				break;
			}
		}
		++this->_size;
	}
	else
	{
		int *temp = new int[this->_size * 2];
		int position = -1;

		for (int i = 0; i < this->_size; ++i)
		{
			temp[i] = this->_vector[i];
			if (&this->_vector[i] == it)
			{
				position = i;
			}
		}
		int current_size = this->_size;

		this->clear();
		this->_vector = temp;
		this->_capacity = current_size * 2;
		this->_size = current_size;

		for (int i = this->_size; i > 0; --i)
		{
			this->_vector[i] = this->_vector[i - 1];
			if (i - 1 == position)
			{
				this->_vector[i - 1] = val;
				break;
			}
		}
		++this->_size;
	}	
}

int ivec::size() const
{
	return this->_size;
}

bool ivec::empty() const
{
	if (this->_size < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ivec::clear()
{
	this->_size = 0;
	this->_capacity = 0;
	delete[] this->_vector;
	this->_vector = nullptr;
}

int ivec::capacity() const
{
	return this->_capacity;
}

int & ivec::back() const
{
	if (this->_size > 0)
	{
		return this->_vector[this->_size - 1];
	}
	else
	{
		throw std::logic_error("Trying access to empty object!!!");
	}
}

int & ivec::front() const
{
	if (this->_size > 0)
	{
		return this->_vector[0];
	}
	else
	{
		throw std::logic_error("Trying access to empty object!!!");
	}
}

int & ivec::at(int index) 
{
	if (index >= this->_size)
	{
		throw std::out_of_range("Trying to access via out of range index!!!");
	}
	else
	{
		return (*this)[index];
	}
}

ivec::~ivec()
{
	this->clear();
}



