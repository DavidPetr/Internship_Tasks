#pragma once
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>

class ivec
{
private:
	int* _vector;
	int _size;
	int _capacity;
public:
	typedef int* iterator;
	typedef const int* const_iterator;
	
	ivec(int from = 0, int to = 0);
	ivec(const ivec& vec);
	ivec& operator=(const ivec& vec);
	//reserve
	//resize

	void push_back(int val);
	void pop_back();
	int& operator[](int index);
	
	iterator begin();
	iterator end();
	
	void erase(const_iterator c_it);
	void insert(iterator it,int val);
	int size() const;
	bool empty() const;
	void clear();
	int capacity() const;
	int& back() const;
	int& front() const;
	int& at(int index);

	~ivec();

};
