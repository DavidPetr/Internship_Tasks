#include "ConcreteExample2.h"
#include "Automaton.cpp"

template class Automaton<toHex::States>;

void toHex::workModifier()
{
	m_StateMachine.work();
}

void toHex::printResult()
{
	m_StateMachine.print();
}

toHex::toHex(const std::string& str) :m_inputString(str)
{}