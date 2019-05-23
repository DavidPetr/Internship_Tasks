#include "ivec.h"


int nearest_power_of_two_integer(int x) 
{
	int i;
	for (i = 2; i < x; i *= 2) {}
	return i;
}

ivec::ivec(int from, int to)
{
	const int n = std::abs(to - from);
	

	this->_capacity = nearest_power_of_two_integer(n);
	this->_vector = new int[this->_capacity];
	this->_size = n;
	
	int j = 0;
	if (n != 0)
	{
		if (from < to)
		{
			for (int i = from; i < to; ++i)
			{
				this->_vector[j++] = i;
			}
		}
		else
		{
			for (int i = from; i > to; --i)
			{
				this->_vector[j++] = i;
			}
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

void ivec::push_back(int val)
{
	if (this->_size < this->_capacity)
	{
		this->_vector[this->_size] = val;
		++this->_size;
	}
	else
	{
		int *temp = new int[this->_size * 2];
		
		int i;
		for (i = 0; i < this->_size; ++i)
		{
			temp[i] = this->_vector[i];
		}
		temp[i] = val;
		int current_size = this->_size;

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
	if (this->_size < this->_capacity)
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

		for (int i = 0; i < this->_size; ++i)
		{
			temp[i] = this->_vector[i];
		}
		int current_size = this->_size;

		this->clear();
		this->_vector = temp;
		this->_capacity = current_size * 2;
		this->_size = current_size;

		for (int i = this->_size; i > 0; --i)
		{
			this->_vector[i] = this->_vector[i - 1];
			if (&this->_vector[i - 1] == it)
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
	return this->_vector[this->_size - 1];
}

int & ivec::front() const
{
	return this->_vector[0];
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
