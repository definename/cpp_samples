#include "pch.h"
#include "City.h"

City* City::city_ = nullptr;

City* City::GetInstance()
{
	if (!city_) {
		city_ = new City();
	}
	return city_;
}

void City::SetRoads(Roads* roads)
{
	roads_ = roads;
}