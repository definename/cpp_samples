#pragma once

#include "WindowBorder.h"
#include "WindowMenu.h"

class Clock : public WindowBorder, WindowMenu
{
public:
	Clock() = default;
	~Clock() {
		std::cout << "Clock has been destroyed" << std::endl;
	}
	void Draw() override {
		WindowBorder::Draw();
		WindowMenu::Draw();
		std::cout << "Clock has been drown" << std::endl;
	}
};