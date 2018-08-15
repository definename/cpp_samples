#pragma once

#include "IClass.h"
class ClassB : public IClass
{
public:
	ClassB();
	~ClassB();

public:
	_tostream& put(_tostream& s) const;

public:
	_tstring val_;
};
