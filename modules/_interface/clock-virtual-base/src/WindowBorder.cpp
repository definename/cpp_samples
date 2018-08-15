#include "pch.h"
#include "WindowBorder.h"

WindowBorder::WindowBorder()
{ }

WindowBorder::~WindowBorder()
{
	_tcout << _T("WindowBorder has been destroyed") << std::endl;
}

void WindowBorder::Draw()
{
	_tcout << _T("Window border has been drown") << std::endl;
}
