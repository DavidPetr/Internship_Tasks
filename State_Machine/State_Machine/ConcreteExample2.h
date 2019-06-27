#pragma once

#include "stdafx.h"
#include "Automaton.h"




class toHex
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
		Q111,
		Q0000,
		Q0001,
		Q0010,
		Q0011,
		Q0100,
		Q0101,
		Q0110,
		Q0111,
		Q1000,
		Q1001,
		Q1010,
		Q1011,
		Q1100,
		Q1101,
		Q1110,
		Q1111
	};
	TransmissionOperator<States> toHexOperator = {
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

		{ std::make_pair(States::Q000,'0'), States::Q0000 },
		{ std::make_pair(States::Q000,'1'), States::Q0001 },
		{ std::make_pair(States::Q001,'0'), States::Q0010 },
		{ std::make_pair(States::Q001,'1'), States::Q0011 },
		{ std::make_pair(States::Q010,'0'), States::Q0100 },
		{ std::make_pair(States::Q010,'1'), States::Q0101 },
		{ std::make_pair(States::Q011,'0'), States::Q0110 },
		{ std::make_pair(States::Q011,'1'), States::Q0111 },
		{ std::make_pair(States::Q100,'0'), States::Q1000 },
		{ std::make_pair(States::Q100,'1'), States::Q1001 },
		{ std::make_pair(States::Q101,'0'), States::Q1010 },
		{ std::make_pair(States::Q101,'1'), States::Q1011 },
		{ std::make_pair(States::Q110,'0'), States::Q1100 },
		{ std::make_pair(States::Q110,'1'), States::Q1101 },
		{ std::make_pair(States::Q111,'0'), States::Q1110 },
		{ std::make_pair(States::Q111,'1'), States::Q1111 },

		{ std::make_pair(States::Q0000,'0'), States::Q },
		{ std::make_pair(States::Q0000,'1'), States::Q },
		{ std::make_pair(States::Q0001,'0'), States::Q },
		{ std::make_pair(States::Q0001,'1'), States::Q },
		{ std::make_pair(States::Q0010,'0'), States::Q },
		{ std::make_pair(States::Q0010,'1'), States::Q },
		{ std::make_pair(States::Q0011,'0'), States::Q },
		{ std::make_pair(States::Q0011,'1'), States::Q },
		{ std::make_pair(States::Q0100,'0'), States::Q },
		{ std::make_pair(States::Q0100,'1'), States::Q },
		{ std::make_pair(States::Q0101,'0'), States::Q },
		{ std::make_pair(States::Q0101,'1'), States::Q },
		{ std::make_pair(States::Q0110,'0'), States::Q },
		{ std::make_pair(States::Q0110,'1'), States::Q },
		{ std::make_pair(States::Q0111,'0'), States::Q },
		{ std::make_pair(States::Q0111,'1'), States::Q },
		{ std::make_pair(States::Q1000,'0'), States::Q },
		{ std::make_pair(States::Q1000,'1'), States::Q },
		{ std::make_pair(States::Q1001,'0'), States::Q },
		{ std::make_pair(States::Q1001,'1'), States::Q },
		{ std::make_pair(States::Q1010,'0'), States::Q },
		{ std::make_pair(States::Q1010,'1'), States::Q },
		{ std::make_pair(States::Q1011,'0'), States::Q },
		{ std::make_pair(States::Q1011,'1'), States::Q },
		{ std::make_pair(States::Q1100,'0'), States::Q },
		{ std::make_pair(States::Q1100,'1'), States::Q },
		{ std::make_pair(States::Q1101,'0'), States::Q },
		{ std::make_pair(States::Q1101,'1'), States::Q },
		{ std::make_pair(States::Q1110,'0'), States::Q },
		{ std::make_pair(States::Q1110,'1'), States::Q },
		{ std::make_pair(States::Q1111,'0'), States::Q },
		{ std::make_pair(States::Q1111,'1'), States::Q }
	};
	const Alphabet m_InputAlphabet = { '0','1' };
	const Alphabet m_OutputAlphabet = { '0','1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7','8','9' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' };

private:
	std::string m_inputString;
	Automaton<States> m_StateMachine{ m_InputAlphabet,m_OutputAlphabet,toHexOperator , States::Q, States::Q, System::Hexadecimal, m_inputString };
public:
	void workModifier();
	void printResult();

	toHex(const std::string& str);
	~toHex()=default;
};

