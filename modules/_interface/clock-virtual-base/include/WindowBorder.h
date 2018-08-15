#pragma once
#include "Window.h"

class WindowBorder : public virtual Window
{
public:
	WindowBorder();
	virtual ~WindowBorder();

public:
	virtual void Draw();
};
