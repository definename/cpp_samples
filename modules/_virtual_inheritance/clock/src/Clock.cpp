#include "pch.h"
#include "Clock.h"

Clock::Clock()
{ }

Clock::~Clock()
{
	_tcout << _T("Clock has been destroyed") << std::endl;
}

void Clock::Draw()
{
	WindowBorder::Draw();
	WindowMenu::Draw();
	_tcout << _T("Clock has been drown") << std::endl;
}
