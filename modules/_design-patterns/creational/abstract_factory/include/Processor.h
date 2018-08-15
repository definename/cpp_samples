#pragma once

#include "IDevice.h"
class Processor : public IDevice
{
public:
	Processor();
	Processor(const _tstring& manufacturer);
	~Processor();

public:
	_tstring GetManufacturer();
	void Start();
	void Stop();

private:
	_tstring manufacturer_;
};