#include "pch.h"
#include "TrafficLight.h"

const std::vector<std::string> ITrafficLight::lightColor_ = { "GREEN", "RED" };

TrafficLight::TrafficLight(int red, int green)
	: ITrafficLight(red, green)
{
}

void TrafficLight::Tick()
{
	if (color_ == LightColor::GREEN && red_ == ticks_)
	{
		color_ = LightColor::RED;
		ticks_ = 0;
	}
	else if (color_ == LightColor::RED && green_ == ticks_)
	{
		color_ = LightColor::GREEN;
		ticks_ = 0;
	}
	std::cout << lightColor_.at(static_cast<int>(color_)) << std::endl;
	ticks_++;
}