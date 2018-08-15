#pragma once

#include "IWarrior.h"
class ICreator
{
public:
	virtual ~ICreator() { }

public:
	virtual IWarrior* CreateWarrior() = 0;
};