#pragma once

#include "IWarrior.h"
class InfantryImpl : public IWarrior
{
public:
	InfantryImpl();
	virtual ~InfantryImpl();

public:
	void Info();
};