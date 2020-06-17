#pragma once

#include "Window.h"

class WindowBorder: public virtual Window
{
public:
	WindowBorder() = default;
	virtual ~WindowBorder() {
		std::cout << "WindowBorder has been destroyed" << std::endl;
	}
	void Draw() override {
		std::cout << "Window border has been drown" << std::endl;
	}
};

