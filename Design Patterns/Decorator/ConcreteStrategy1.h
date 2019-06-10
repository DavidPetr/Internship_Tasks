#pragma once
#include "stdafx.h"

class HeapSort final :public Strategy
{
public:
	HeapSort(std::vector<int> vector);

private:
	virtual void sort(std::vector<int>& vector) override;
};