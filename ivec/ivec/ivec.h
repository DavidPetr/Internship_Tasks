#pragma once
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
class ivec
{
private:
	int* _vector = nullptr;
	int _size;
	int _capacity;
public:
	typedef int* iterator;
	typedef const int* const_iterator;
	
	ivec(int size = 0, int value = 0);
	ivec(const ivec& vec);
	ivec& operator=(const ivec& vec);
	void reserve(int n);
	void resize(int n, int val = 0);

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
