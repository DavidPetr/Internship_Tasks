#include "ConcreteExample1.h"
#include "Automaton.cpp"

template class Automaton<toOct::States>;

void toOct::workModifier()
{
	m_StateMachine.work();
}

void toOct::printResult()
{
	m_StateMachine.print();
}

toOct::toOct(const std::string& str):m_inputString(str)
{}


