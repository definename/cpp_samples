#pragma once

#include "IWarrior.h"
class CavalryImpl : public IWarrior
{
public:
	CavalryImpl();
	virtual ~CavalryImpl();

public:
	void Info();
};