#pragma once

class IClass
{
public:
	virtual ~IClass() { }

public:
	virtual _tostream& put(_tostream&) const = 0;
};