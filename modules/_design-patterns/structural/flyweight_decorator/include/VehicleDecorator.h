#pragma once

#include "Vehicle.h"

class IVehicleDecorator : public IVehicle
{

public:
	IVehicleDecorator(IVehicle* vehicle)
		: vehicle_(vehicle) 
	{
	}

	~IVehicleDecorator() = default;

protected:
	IVehicle* vehicle_;
};

class VehicleDecoratorFast : public IVehicleDecorator
{
public:
	VehicleDecoratorFast(IVehicle* vehicle, int diff);
	~VehicleDecoratorFast() = default;

public:
	virtual int GetSpeed() override;

private:
	int diff_;
};

class VehicleDecoratorSlow : public IVehicleDecorator
{
public:
	VehicleDecoratorSlow(IVehicle* vehicle, int diff);
	~VehicleDecoratorSlow() = default;

public:
	virtual int GetSpeed() override;

private:
	int diff_;
};