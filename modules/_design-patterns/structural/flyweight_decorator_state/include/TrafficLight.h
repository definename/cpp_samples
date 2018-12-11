#pragma once

#include "TrafficLightState.h"

class ITrafficLight
{

public:
	ITrafficLight(int tickRed, int tickGreen)
		: tickRed_(tickRed)
		, tickGreen_(tickGreen)
		, state_(nullptr)
	{
	}

	virtual ~ITrafficLight() = default;

public:
	virtual void Tick() = 0;
	void SetState(ITrafficLightState* state)
	{
		if (state_ != nullptr) {
			delete state_;
		}
		state_ = state;
	}

protected:
	int tickRed_;
	int tickGreen_;
	ITrafficLightState* state_;
};

class TrafficLightRedGreen : public ITrafficLight
{
public:
	TrafficLightRedGreen(int tickRed, int tickGreen);
	~TrafficLightRedGreen() = default;

public:
	virtual void Tick() override;
	void ChangeState(ITrafficLightState::LightStateColor color);
};