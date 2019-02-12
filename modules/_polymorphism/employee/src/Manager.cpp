#include "pch.h"
#include "Manager.h"

Manager::Manager(const _tstring& name, const int& level)
	: Employee(name)
	, level_(level)
{ }

void Manager::Print()
{
	Employee::Print();
	_tcout << "level: " << level_ << std::endl;
}