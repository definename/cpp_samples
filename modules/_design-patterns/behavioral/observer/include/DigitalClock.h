#pragma once

#include "IObserver.h"
class DigitalClock : public IObserver
{
public:
	DigitalClock();
	~DigitalClock();

public:
	void Update(const _tstring& time);
};