#include "pch.h"
#include "City.h"
#include "TrafficLightsFactory.h"
#include "VehicleDecorator.h"

int main(int argc, char* argv[])
{
	City* city = City::GetInstance();
	city->SetRoads(new Roads());

	// Decorator pattern
	IVehicle* vehicle = new Vehicle();
	std::cout << "Normal speed:" << vehicle->GetSpeed() << std::endl;
	IVehicleDecorator* vehicleFast = new VehicleDecoratorFast(vehicle, 10);
	std::cout << "Fast speed:" << vehicleFast->GetSpeed() << std::endl;
	IVehicleDecorator* vehicleSlow = new VehicleDecoratorSlow(vehicleFast, 2);
	std::cout << "Slow speed:" << vehicleSlow->GetSpeed() << std::endl;

	// Flyweight pattern
	auto factory = TrafficLightsFactory();
	factory.CreateTrafficLight(2, 3);
	for (;;)
	{
		factory.Tick();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}