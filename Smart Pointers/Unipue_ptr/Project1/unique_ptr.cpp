#include "Vehicle.h"

int main()
{
	std::unique_ptr<Vehicle> halfBycycle = std::move(Vehicle::Create(1));
	std::unique_ptr<Vehicle> bycycle = std::move(Vehicle::Create(2));
	std::unique_ptr<Vehicle> moto = std::move(Vehicle::Create(3));
	std::unique_ptr<Vehicle> car = std::move(Vehicle::Create(4));
	
	halfBycycle->printVehicle();
	bycycle->printVehicle();
	moto->printVehicle();
	car->printVehicle();
	
	getchar();
	return 0;
}

