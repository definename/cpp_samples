#pragma once

#include "IDevice.h"
class VideoCard : public IDevice
{
public:
	VideoCard();
	VideoCard(const _tstring& manufacturer);
	~VideoCard();

public:
	_tstring GetManufacturer();
	void Start();
	void Stop();

private:
	_tstring manufacturer_;
};