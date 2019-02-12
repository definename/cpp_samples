#include "pch.h"
#include "Employee.h"

Employee::Employee(_tstring name)
	: name_(name)
{ }

Employee::~Employee()
{
	_tcout << _T("Employee ") << name_ << _T(" has been fired") << std::endl;
}

void Employee::Print()
{
	_tcout << "name: " << name_ << std::endl;
}
