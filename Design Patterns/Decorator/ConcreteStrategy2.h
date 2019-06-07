#pragma once
#include "stdafx.h"

class MergeSort final :public Strategy
{
public:
	MergeSort(std::vector<int> vector);

private:
	void merge(std::vector<int> vector, int leftIndex, int rightIndex);
	void mergeSort(std::vector<int> vector, int leftIndex, int rightIndex);
	virtual void sort(std::vector<int>& vector) override;
};