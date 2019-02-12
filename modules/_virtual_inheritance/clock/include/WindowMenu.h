#pragma once
#include "Window.h"

class WindowMenu : public virtual Window
{
public:
	WindowMenu();
	virtual ~WindowMenu();

public:
	virtual void Draw();
};