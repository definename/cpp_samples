#pragma once

#include "IFactory.h"
class IntelFactory : public IFactory
{
public:
	IntelFactory();
	virtual ~IntelFactory();

public:
	IDevice* GetProcessorInstance();
	IDevice* GetVideoCardInstance();
};