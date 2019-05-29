#pragma once
#include "Interface.h"
class Basic final :public AntiVirus
{
public:
	virtual void ProtectionLevel() override
	{
		AntiVirus::index = 0;
		std::cout << ++AntiVirus::index << ". " << "Protect my computer" << std::endl;
		std::cout << ++AntiVirus::index << ". " << "Keep me safe from attacks" << std::endl;
	}
	virtual ~Basic()
	{
		std::cout << "Destructor of Basic" << std::endl;
	}
};