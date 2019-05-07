#pragma once
#include <iostream>
#include <memory>


class Vehicle
{
public:
	virtual void printVehicle() = 0;
	static std::unique_ptr<Vehicle> Create(int WheelCount);
};
class OneWheeler : public Vehicle
{
	void printVehicle()
	{
		std::cout << "One Wheel" << std::endl;
	}
};
class TwoWheeler : public Vehicle
{
	void printVehicle()
	{
		std::cout << "Two Wheel" << std::endl;
	}
};
class ThreeWheeler : public Vehicle
{
	void printVehicle()
	{
		std::cout << "Three Wheel" << std::endl;
	}
};
class FourWheeler : public Vehicle
{
	void printVehicle()
	{
		std::cout << "Four Wheel" << std::endl;
	}
};