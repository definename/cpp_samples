#pragma once

#include "ICreator.h"
class InfantryCreator : public ICreator
{
public:
	InfantryCreator();
	virtual ~InfantryCreator();

public:
	IWarrior* CreateWarrior();
};