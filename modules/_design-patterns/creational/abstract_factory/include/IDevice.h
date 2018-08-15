#pragma once

class IDevice
{
public:
	virtual ~IDevice() { };

public:
	virtual _tstring GetManufacturer() = 0;
	virtual void Start() = 0;
	virtual void Stop() = 0;
};