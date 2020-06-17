#pragma once

class Window {
public:
	virtual ~Window() = default;
	virtual void Draw() = 0;
};