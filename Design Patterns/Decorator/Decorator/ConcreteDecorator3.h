#pragma once
#include "Decorator.h"
class Encrypt : public AntiVirusDecorator
{
private:
	void EncryptPassword()
	{
		std::cout << ++AntiVirus::index << ". ";
		std::cout << "Safely store and prefill my passwords (so that I don't have to remember them)" << std::endl;
	}
	void EncryptPhotos()
	{
		std::cout << ++AntiVirus::index << ". ";
		std::cout << "Encrypt my photos (so nobody else can see them)" << std::endl;
	}
public:
	Encrypt(AntiVirus& decorator) :AntiVirusDecorator(decorator)
	{}

	virtual void Protect() override
	{
		AntiVirusDecorator::Protect();
		EncryptPassword();
		EncryptPhotos();
	}
	virtual ~Encrypt()
	{
		std::cout << "Destructor of Encrypt" << std::endl;
	}
};
