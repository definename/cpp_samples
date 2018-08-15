#pragma once

#include "WindowBorder.h"
#include "WindowMenu.h"

class Clock : public WindowBorder, WindowMenu
{
public:
	Clock();
	~Clock();

public:
	void Draw();
};