#pragma once

#include "IDevice.h"
class IFactory
{
public:
	virtual ~IFactory() { };

public:
	virtual IDevice* GetProcessorInstance() = 0;
	virtual IDevice* GetVideoCardInstance() = 0;
};