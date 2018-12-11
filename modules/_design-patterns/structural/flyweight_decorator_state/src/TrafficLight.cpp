#include "pch.h"
#include "TrafficLight.h"

TrafficLightRedGreen::TrafficLightRedGreen(int tickRed, int tickGreen)
	: ITrafficLight(tickRed, tickGreen)
{
	SetState(new TrafficLightStateGreen(tickGreen));
}

void TrafficLightRedGreen::Tick()
{
	if (state_->Tick() == 0) {
		ChangeState(state_->GetColor());
	}
}

void TrafficLightRedGreen::ChangeState(ITrafficLightState::LightStateColor color)
{
	if (color == ITrafficLightState::LightStateColor::GREEN) {
		SetState(new TrafficLightStateRed(tickRed_));
	}
	else if (color == ITrafficLightState::LightStateColor::RED) {
		SetState(new TrafficLightStateGreen(tickGreen_));
	}
	else {
		std::cout << "Invalid state" << std::endl;
	}
}