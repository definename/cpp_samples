#pragma once

#include "IClass.h"
class ClassA : public IClass
{
public:
	ClassA();
	~ClassA();

public:
	_tostream& put(_tostream& s) const;

public:
	_tstring val_;
};
