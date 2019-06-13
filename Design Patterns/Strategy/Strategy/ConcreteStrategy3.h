#pragma once
#include "stdafx.h"

class QuickSort :public Strategy
{
public:
	QuickSort(const iVec& vector);

private:
	void quick(iVec& vector, int low, int high);
	int partition(iVec& vector, int low, int high);

	virtual void sort(iVec& vector) override;
};
