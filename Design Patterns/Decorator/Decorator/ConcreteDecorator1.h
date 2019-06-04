#pragma once
#include "Decorator.h"
class StopHackers : public AntiVirusDecorator
{
private:
	void KeepHackersAway() 
	{
		std::cout << ++AntiVirus::index << ". ";
		std::cout << "Create traps and catch hackers attacks" << std::endl;
	}
public:
	StopHackers(AntiVirus& decorator) :AntiVirusDecorator(decorator)
	{}

	virtual void Protect() override
	{
		AntiVirusDecorator::Protect();
		KeepHackersAway();
	}
	virtual ~StopHackers()
	{
		std::cout << "Destructor of StopHackers" << std::endl;
	}
};
