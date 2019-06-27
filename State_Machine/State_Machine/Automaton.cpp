#include "Automaton.h"


template<typename stateTemplate>
Automaton<stateTemplate>::Automaton(const Alphabet & inputAlphabet
					, const Alphabet & outputAlphabet
					, const TransmissionOperator<stateTemplate> & transOperator
					, const stateTemplate & initialState
					, const stateTemplate & finalState
					, const System & SysType
					, const std::string & input)
	:
	m_inputAlphabet(inputAlphabet),
	m_outputAlphabet(outputAlphabet),
	m_transmissionOperator(transOperator),
	m_initialState(initialState),
	m_SysType(SysType),
	m_finalState(finalState)
{
	for (auto i : input)
	{
		m_inputLine.push_back(i);
	}

	for (auto& key_value : m_transmissionOperator)
	{
		if (key_value.second == m_finalState)
		{
			m_minSecondFinalState = key_value.first.first;
			break;
		}
	}
}

template<typename stateTemplate>
Automaton<stateTemplate>::~Automaton()
{
	std::cout << std::endl << "Destructor Automaton!!!" << std::endl;
}

template<typename stateTemplate>
void Automaton<stateTemplate>::handler(const stateTemplate& errorState, const char& item)
{
	auto search = std::find(m_inputAlphabet.begin(), m_inputAlphabet.end(), item);
	if (errorState != stateTemplate::Q || search == m_inputAlphabet.end())
	{
		std::cout << "Automaton doesn't reach to final state, and stops in " <<
			static_cast<std::underlying_type<stateTemplate>::type>(errorState) << " state." <<
			std::endl << "Accordingly result is invalid.!!!" << std::endl;
	}
	else
	{
		std::cout << "Automaton reach to final state, result is valid !!!" << std::endl;
	}
}

template<typename stateTemplate>
void Automaton<stateTemplate>::setinputLine(const std::string & input)
{
	m_inputLine.clear();
	for (auto i : input)
	{
		m_inputLine.push_back(i);
	}
}

template<typename stateTemplate>
void Automaton<stateTemplate>::work()
{
	int value_m_SysType = static_cast<std::underlying_type<stateTemplate>::type>(m_SysType);

	int count = m_inputLine.size() % value_m_SysType;	/// count of bits that less than SysType 
	if (count != 0)
	{
		m_inputLine.insert(m_inputLine.begin(), value_m_SysType - count, '0');		/// push '0' as many as Systype requires to become m_inputAlphabet complete  
	}

	stateTemplate nextState = m_initialState;
	char item;

	for (int i = 0; i < m_inputLine.size();++i)
	{
		item = m_inputLine[i];

		auto search = m_transmissionOperator.find(std::make_pair(nextState, item));

		if (search == m_transmissionOperator.end())
		{
			break;
		}
		nextState = search->second;
		std::cout << "State " << static_cast<std::underlying_type<stateTemplate>::type>(nextState) << std::endl;
		
		
		if (nextState >= m_minSecondFinalState)
		{
			int index1 = static_cast<std::underlying_type<stateTemplate>::type>(nextState);
			int index2 = static_cast<std::underlying_type<stateTemplate>::type>(m_minSecondFinalState);
			int index = index1 - index2;
			m_outputLine.push_back(m_outputAlphabet[index]);
			--i;
		}

	}
	handler(nextState,item);
}

template<typename stateTemplate>
void Automaton<stateTemplate>::print()
{
	std::cout << "Result is ";
	for (auto i : m_outputLine)
	{
		std::cout << i;
	}
	std::cout << std::endl;
}

