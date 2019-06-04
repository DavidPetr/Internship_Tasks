#pragma once
#include <iostream>

class AntiVirus
{
protected:
	static int index;	/// for numbering 
public:
	virtual void Protect() = 0;
	virtual ~AntiVirus()
	{ 
		std::cout << "Destructor of Interface" << std::endl; 
		getchar();
	}

};
int AntiVirus::index = 0;
