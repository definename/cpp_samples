#pragma once

class Window
{
public:
	virtual ~Window() { };

public:
	virtual void Draw() = 0;
};