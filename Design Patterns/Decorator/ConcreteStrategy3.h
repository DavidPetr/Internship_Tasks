#pragma once
#include "stdafx.h"

class QuickSort :public Strategy
{
public:
	QuickSort(std::vector<int> vector);

private:
	void quick(std::vector<int>& vector, int low, int high);
	int partition(std::vector<int>& vector, int low, int high);

	virtual void sort(std::vector<int>& vector) override;
};
