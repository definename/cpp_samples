#include "pch.h"
#include "ClassA.h"

ClassA::ClassA()
	: val_(_T("Class name A"))
{ }

ClassA::~ClassA()
{ }

_tostream& ClassA::put(_tostream& s) const
{
	return s << val_;
}