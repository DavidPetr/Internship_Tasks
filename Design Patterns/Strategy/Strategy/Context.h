#pragma once

#include "stdafx.h"

using SpStrategy = std::shared_ptr<Strategy>;

class Heap final
{
public:
	Heap(const SpStrategy& strategy);

	void doIt();
	
private:
	SpStrategy m_strategy;
};