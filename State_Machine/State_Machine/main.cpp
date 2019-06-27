#include "stdafx.h"
#include "ConcreteExample1.h"
#include "ConcreteExample2.h"

int main(int argc, char** argv)
{
	Alphabet input;
	std::string s;
	std::cin >> s;

	toOct ObjOct(s);
	toHex ObjHex(s);
	
	
	ObjOct.workModifier();
	ObjOct.printResult();
	

	ObjHex.workModifier();
	ObjHex.printResult();

	
	/*enum class States
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

	States m_finalState = States::Q;
	m_finalState

	for (auto& key_value : toOctOperator)
	{
		if (key_value.second == m_finalState)
		{
			m_minSecondFinalState = (key_value.key).first;
		}
	}*/

	getchar();
	getchar();
	return 0;
}