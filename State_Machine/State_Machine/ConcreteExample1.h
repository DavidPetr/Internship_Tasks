#pragma once

#include "stdafx.h"
#include "Automaton.h"




class toOct
{
private:
	enum class States
	{
		Q = 0,	/// initial and final state
		Q0,
		Q1,
		Q00,
		Q01,
		Q10,
		Q11,
		Q000,
		Q001,
		Q010,
		Q011,
		Q100,
		Q101,
		Q110,
		Q111
	};
	TransmissionOperator<States> toOctOperator = {
		{ std::make_pair(States::Q,'0'), States::Q0 },
		{ std::make_pair(States::Q,'1'), States::Q1 },
		{ std::make_pair(States::Q0,'0'), States::Q00 },
		{ std::make_pair(States::Q0,'1'), States::Q01 },
		{ std::make_pair(States::Q1,'0'), States::Q10 },
		{ std::make_pair(States::Q1,'1'), States::Q11 },
		{ std::make_pair(States::Q00,'0'), States::Q000 },
		{ std::make_pair(States::Q00,'1'), States::Q001 },
		{ std::make_pair(States::Q01,'0'), States::Q010 },
		{ std::make_pair(States::Q01,'1'), States::Q011 },
		{ std::make_pair(States::Q10,'0'), States::Q100 },
		{ std::make_pair(States::Q10,'1'), States::Q101 },
		{ std::make_pair(States::Q11,'0'), States::Q110 },
		{ std::make_pair(States::Q11,'1'), States::Q111 },

		{ std::make_pair(States::Q000,'0'), States::Q },
		{ std::make_pair(States::Q000,'1'), States::Q },
		{ std::make_pair(States::Q001,'0'), States::Q },
		{ std::make_pair(States::Q001,'1'), States::Q },
		{ std::make_pair(States::Q010,'0'), States::Q },
		{ std::make_pair(States::Q010,'1'), States::Q },
		{ std::make_pair(States::Q011,'0'), States::Q },
		{ std::make_pair(States::Q011,'1'), States::Q },
		{ std::make_pair(States::Q100,'0'), States::Q },
		{ std::make_pair(States::Q100,'1'), States::Q },
		{ std::make_pair(States::Q101,'0'), States::Q },
		{ std::make_pair(States::Q101,'1'), States::Q },
		{ std::make_pair(States::Q110,'0'), States::Q },
		{ std::make_pair(States::Q110,'1'), States::Q },
		{ std::make_pair(States::Q111,'0'), States::Q },
		{ std::make_pair(States::Q111,'1'), States::Q }
	};
	const Alphabet m_InputAlphabet = { '0','1' };
	const Alphabet m_OutputAlphabet = { '0','1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' };

private:	
	std::string m_inputString;
	Automaton<States> m_StateMachine{ m_InputAlphabet,m_OutputAlphabet,toOctOperator , States::Q, States::Q, System::Octal, m_inputString };
public:
	void workModifier();
	void printResult();
	
	toOct(const std::string& str);
	~toOct() = default;
};

