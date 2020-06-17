#pragma once

#include "Window.h"

class WindowMenu : public virtual Window
{
public:
	WindowMenu() = default;
	virtual ~WindowMenu() {
		std::cout << "WindowMenu has been destroyed" << std::endl;
	}
	virtual void Draw() override {
		std::cout << "Window menu has been drown" << std::endl;
	}
};