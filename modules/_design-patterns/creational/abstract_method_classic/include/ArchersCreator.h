#pragma once

#include "ICreator.h"
class ArchersCreator : public ICreator
{
public:
	ArchersCreator();
	virtual ~ArchersCreator();

public:
	IWarrior* CreateWarrior();
};