#include "pch.h"
#include "AnalogClock.h"

AnalogClock::AnalogClock()
{ }

AnalogClock::~AnalogClock()
{ }

void AnalogClock::Update(const _tstring& time)
{
	_tcout << _T("Analog time: ") << time << std::endl;
}