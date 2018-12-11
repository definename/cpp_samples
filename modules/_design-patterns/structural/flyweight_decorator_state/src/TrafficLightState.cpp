#include "pch.h"
#include "TrafficLightState.h"

TrafficLightStateRed::TrafficLightStateRed(const int ticks)
	: ITrafficLightState(ticks, LightStateColor::RED)
{

}

int TrafficLightStateRed::Tick()
{
	std::cout << "Red" << std::endl;
	return --ticks_;
}

TrafficLightStateGreen::TrafficLightStateGreen(const int ticks)
	: ITrafficLightState(ticks, LightStateColor::GREEN)
{

}

int TrafficLightStateGreen::Tick()
{
	std::cout << "Green" << std::endl;
	return --ticks_;
}