#pragma once

#include "stdafx.h"

template <typename stateTemplate>
class Automaton
{
protected:
	Alphabet m_inputAlphabet;
	Alphabet m_outputAlphabet;
	TransmissionOperator<stateTemplate> m_transmissionOperator;
	stateTemplate m_initialState;
	stateTemplate m_finalState;
	Result m_outputLine;
	System m_SysType;
	Input m_inputLine;
	stateTemplate m_minSecondFinalState;
protected:
	void handler(const stateTemplate& errorState, const char& item);
	
public:
	Automaton(const Alphabet & inputAlphabet
		, const Alphabet & outputAlphabet
		, const TransmissionOperator<stateTemplate> & transOperator
		, const stateTemplate & initialState
		, const stateTemplate & finalState
		, const System & SysType
		, const std::string & input);
	~Automaton();

	void setinputLine(const std::string & input);
	void work();
	void print();
};
