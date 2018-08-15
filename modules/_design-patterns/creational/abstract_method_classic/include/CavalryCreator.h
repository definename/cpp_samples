#pragma once

#include "ICreator.h"
class CavalryCreator : public ICreator
{
public:
	CavalryCreator();
	virtual ~CavalryCreator();

public:
	IWarrior* CreateWarrior();
};