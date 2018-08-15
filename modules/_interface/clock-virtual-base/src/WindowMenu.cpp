#include "pch.h"
#include "WindowMenu.h"

WindowMenu::WindowMenu()
{ }

WindowMenu::~WindowMenu()
{
	_tcout << _T("WindowMenu has been destroyed") << std::endl;
}

void WindowMenu::Draw()
{
	_tcout << _T("Window menu has been drown") << std::endl;
}