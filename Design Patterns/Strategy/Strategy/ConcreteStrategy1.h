#pragma once
#include "stdafx.h"

class HeapSort final :public Strategy
{
public:
	HeapSort(const iVec& vector);

private:
	virtual void sort(iVec& vector) override;
};