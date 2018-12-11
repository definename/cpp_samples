#include "pch.h"
#include "VehicleDecorator.h"

VehicleDecoratorFast::VehicleDecoratorFast(IVehicle* vehicle, const int diff)
	: IVehicleDecorator(vehicle)
	, diff_(diff)
{

}

int VehicleDecoratorFast::GetSpeed()
{
	return vehicle_->GetSpeed() + diff_;
}

VehicleDecoratorSlow::VehicleDecoratorSlow(IVehicle* vehicle, const int diff)
	: IVehicleDecorator(vehicle)
	, diff_(diff)
{

}

int VehicleDecoratorSlow::GetSpeed()
{
	return vehicle_->GetSpeed() - diff_;
}
