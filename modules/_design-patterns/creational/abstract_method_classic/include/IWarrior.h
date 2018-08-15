#pragma once

class IWarrior
{
public:
	virtual ~IWarrior() { }

public:
	virtual void Info() = 0;
};