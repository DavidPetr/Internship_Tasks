#pragma once
#include "stdafx.h"

class BubleSort final :public Strategy
{
public:
	BubleSort(std::vector<int> vector);

private:
	virtual void sort(std::vector<int>& vector) override;
};