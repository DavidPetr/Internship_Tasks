#pragma once
#include "Decorator.h"
class ShopSafe : public AntiVirusDecorator
{
private:
	void Transaction()
	{
		std::cout << ++AntiVirus::index << ". ";
		std::cout << "Enable me to shop and bank online (knowing that my transactions are safe)" << std::endl;
	}
public:
	ShopSafe(AntiVirus& decorator) :AntiVirusDecorator(decorator)
	{}

	virtual void Protect() override
	{
		AntiVirusDecorator::Protect();
		Transaction();
	}
	virtual ~ShopSafe()
	{
		std::cout << "Destructor of ShopSafe" << std::endl;
	}
};
