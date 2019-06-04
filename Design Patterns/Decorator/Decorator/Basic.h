#pragma once
#include "Interface.h"
class Basic final :public AntiVirus
{
private:
	void ScanMyPC()
	{
		std::cout << ++AntiVirus::index << ". ";
		std::cout << "Scan my computer and delete viruses" << std::endl;
	}
public:
	virtual void Protect() override
	{
		AntiVirus::index = 0;
		ScanMyPC();
	}
	virtual ~Basic()
	{
		std::cout << "Destructor of Basic" << std::endl;
	}
};