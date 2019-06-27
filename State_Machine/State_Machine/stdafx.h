#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

enum class System
{
	Octal = 3,
	Hexadecimal = 4
};

using Alphabet = std::vector<char>;
using Result = std::vector<char>;
using Input = std::vector<char>;

template <typename stateTemplate>
using TransmissionOperator = std::map <std::pair<stateTemplate, char>, stateTemplate>;

