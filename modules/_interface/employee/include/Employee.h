#pragma once

class Employee
{
public:
	Employee(_tstring name);
	virtual ~Employee();

public:
	virtual void Print();

private:
	_tstring name_;
};