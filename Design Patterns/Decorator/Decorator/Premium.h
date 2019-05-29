#pragma once
#include "Decorator.h"

class PremiumAntiVirus : public AntiVirusDecorator
{

public:
	PremiumAntiVirus(AntiVirus& decorator) :AntiVirusDecorator(decorator)
	{}

	virtual void ProtectionLevel() override
	{
		AntiVirusDecorator::ProtectionLevel();
		std::cout << ++AntiVirus::index << ". " << "Safely store and prefill my passwords (so that I don't have to remember them)" << std::endl;
		std::cout << ++AntiVirus::index << ". " << "Encrypt my photos (so nobody else can see them)" << std::endl;
	}
	virtual ~PremiumAntiVirus()
	{
		std::cout << "Destructor of PremiumAntiVirus" << std::endl;
	}
};