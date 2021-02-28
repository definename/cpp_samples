#include "pch.h"
#include "ClassB.h"

ClassB::ClassB()
	: val_(_T("Class name B"))
{ }

ClassB::~ClassB()
{ }

_tostream& ClassB::put(_tostream& s) const
{
	return s << val_;
}

