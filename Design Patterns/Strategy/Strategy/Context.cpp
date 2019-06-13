#include "Context.h"

Heap::Heap(const SpStrategy& strategy) : m_strategy(strategy)
{}

void Heap::doIt()
{
	(*m_strategy).print();
}
