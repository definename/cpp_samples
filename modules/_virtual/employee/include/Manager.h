#pragma once

#include "Employee.h"

class Manager : public Employee
{
public:
	Manager(const _tstring& name, const int& level);
	~Manager() = default;

public:
	virtual void Print() override;

private:
	int level_;
};