#include "Vehicle.h"



std::unique_ptr<Vehicle> Vehicle::Create(int WheelCount)
{
	std::unique_ptr<Vehicle> uptrVehicle(nullptr);
	if (WheelCount == 1)
	{
		uptrVehicle.reset(new OneWheeler);
		return uptrVehicle;
	}
	else if (WheelCount == 2)
	{
		uptrVehicle.reset(new TwoWheeler);
		return uptrVehicle;
	}
	else if (WheelCount == 3)
	{
		uptrVehicle.reset(new ThreeWheeler);
		return uptrVehicle;
	}
	else if (WheelCount == 4)
	{
		uptrVehicle.reset(new FourWheeler);
		return uptrVehicle;
	}
	else return nullptr;
}