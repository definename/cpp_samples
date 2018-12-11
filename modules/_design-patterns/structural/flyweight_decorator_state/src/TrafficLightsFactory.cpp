#include "pch.h"
#include "TrafficLightsFactory.h"

ITrafficLight*  TrafficLightsFactory::CreateTrafficLight(int red, int green)
{
	auto unique = std::make_pair(red, green);
	if (trafficLights_.count(unique) == 0) {
		trafficLights_[unique] = new TrafficLightRedGreen(red, green);
	}
	return trafficLights_[unique];

}

void TrafficLightsFactory::Tick()
{
	for (auto& light : trafficLights_) {
		light.second->Tick();
	}
}