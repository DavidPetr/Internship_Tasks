#pragma once
#include "stdafx.h"

class MergeSort final :public Strategy
{
public:
	MergeSort(const iVec& vector);

private:
	void merge(iVec& vector, int leftIndex,int middleIndex, int rightIndex);
	void mergeSort(iVec& vector, int leftIndex, int rightIndex);
	virtual void sort(iVec& vector) override;
};