#pragma once
#include "Interface.h"

class AntiVirusDecorator :public AntiVirus
{
public:
	AntiVirusDecorator(AntiVirus& decorator) :m_Decorator(decorator)
	{}

	virtual void Protect() override
	{
		m_Decorator.Protect();
	}
	virtual ~AntiVirusDecorator()
	{
		std::cout << "Destructor of Decorator" << std::endl;
	}
private:
	AntiVirus& m_Decorator;
};