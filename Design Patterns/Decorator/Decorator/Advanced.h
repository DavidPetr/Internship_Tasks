#pragma once
#include "Decorator.h"
class AdvancedAntiVirus : public AntiVirusDecorator
{

public:
	AdvancedAntiVirus(AntiVirus& decorator) :AntiVirusDecorator(decorator)
	{}

	virtual void ProtectionLevel() override
	{
		AntiVirusDecorator::ProtectionLevel();
		std::cout << ++AntiVirus::index << ". " << "Stop hackers (from accessing my computer)" << std::endl;
		std::cout << ++AntiVirus::index << ". " << "Enable me to shop and bank online (knowing that my transactions are safe)" << std::endl;
	}
	virtual ~AdvancedAntiVirus()
	{
		std::cout << "Destructor of AdvancedAntiVirus" << std::endl;
	}
};