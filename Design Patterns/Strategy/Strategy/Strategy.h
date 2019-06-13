#pragma once
#include "stdafx_stl.h"

using iVec = std::vector<int>;

class Strategy 
{
public:
	Strategy(const iVec& vector);
	void print();
	
protected:
	iVec m_vector;

protected:
	void swap(int& a, int& b) noexcept;

private:	
	virtual void sort(iVec& vector) = 0;
	
};