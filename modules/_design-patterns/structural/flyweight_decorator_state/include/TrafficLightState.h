#pragma once

class ITrafficLightState
{
public:
	enum class LightStateColor
	{
		GREEN = 0,
		RED,
	};

public:
	ITrafficLightState(const int ticks, LightStateColor color)
		: ticks_(ticks)
		, color_(color)
	{
	}

	virtual ~ITrafficLightState() = default;

public:
	virtual int Tick() = 0;

	LightStateColor GetColor() const {
		return color_;
	}

protected:
	LightStateColor color_;
	int ticks_;
};

class TrafficLightStateRed : public ITrafficLightState
{
public:
	TrafficLightStateRed(const int ticks);
	~TrafficLightStateRed() = default;

public:
	int Tick() override;
};

class TrafficLightStateGreen : public ITrafficLightState
{
public:
	TrafficLightStateGreen(const int ticks);
	~TrafficLightStateGreen() = default;

public:
	int Tick() override;
};