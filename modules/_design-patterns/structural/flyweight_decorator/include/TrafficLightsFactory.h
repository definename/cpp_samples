#pragma once

#include "TrafficLight.h"

class TrafficLightsFactory
{
public:
	TrafficLightsFactory() = default;
	~TrafficLightsFactory() = default;

public:
	using TrafficLightsCollection = std::map<std::pair<int, int>, ITrafficLight*>;

public:
	ITrafficLight* CreateTrafficLight(int red, int green);

	void Tick();

private:
	TrafficLightsCollection trafficLights_;
};