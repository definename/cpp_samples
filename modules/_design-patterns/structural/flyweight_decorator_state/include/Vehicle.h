#pragma once

class IVehicle
{
public:
	IVehicle()
		: speed_(10)
	{
	}
	virtual ~IVehicle() = default;

	virtual int GetSpeed() = 0;

protected:
	int speed_;
};

class Vehicle : public IVehicle
{
public:
	int GetSpeed() override;
};