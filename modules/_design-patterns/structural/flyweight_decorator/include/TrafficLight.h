#pragma once

class ITrafficLight
{
public:
	enum class LightColor
	{
		GREEN = 0,
		RED,
	};

public:
	ITrafficLight(int red, int green, LightColor color = LightColor::GREEN)
		: red_(red)
		, green_(green)
		, color_(color)
		, ticks_(0)
	{
	}

public:
	virtual void Tick() = 0;

protected:
	static const std::vector<std::string> lightColor_;
	int red_;
	int green_;
	LightColor color_;
	int ticks_;
};

class TrafficLight : public ITrafficLight
{
public:
	TrafficLight(int red, int green);
	~TrafficLight() = default;

public:
	virtual void Tick() override;

};