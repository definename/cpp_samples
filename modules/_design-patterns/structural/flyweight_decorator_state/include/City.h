#pragma once

#include "Roads.h"

class City
{
public:
	static City* GetInstance();
	void SetRoads(Roads* roads);

private:
	City() = default;
	~City() = default;

private:
	static City* city_;
	Roads* roads_;

};