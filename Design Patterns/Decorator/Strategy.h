#pragma once
#include "stdafx_stl.h"

class Strategy 
{
public:
	Strategy(std::vector<int> v);
	void print();
	
protected:
	std::vector<int> m_vector;

protected:
	void swap(int& a, int& b);

private:	
	virtual void sort(std::vector<int>& vector) = 0;
	
};