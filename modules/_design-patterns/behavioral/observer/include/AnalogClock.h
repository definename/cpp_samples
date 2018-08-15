#pragma once

#include "IObserver.h"
class AnalogClock : public IObserver
{
public:
	AnalogClock();
	~AnalogClock();

public:
	void Update(const _tstring& time);
};