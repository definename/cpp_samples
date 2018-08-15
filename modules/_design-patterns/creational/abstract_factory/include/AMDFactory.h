#pragma once

#include "IFactory.h"
class AMDFactory : public IFactory
{
public:
	AMDFactory();
	virtual ~AMDFactory();

public:
	IDevice* GetProcessorInstance();
	IDevice* GetVideoCardInstance();
};