#pragma once

#include "IWarrior.h"
class ArchersImpl : public IWarrior
{
public:
	ArchersImpl();
	virtual ~ArchersImpl();

public:
	void Info();
};