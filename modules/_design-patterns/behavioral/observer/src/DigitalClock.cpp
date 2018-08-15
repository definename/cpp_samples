#include "pch.h"
#include "DigitalClock.h"

DigitalClock::DigitalClock()
{ }

DigitalClock::~DigitalClock()
{ }

void DigitalClock::Update(const _tstring& time)
{
	_tcout << _T("Digital time: ") << time << std::endl;
}