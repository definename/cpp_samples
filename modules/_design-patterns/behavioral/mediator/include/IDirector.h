#pragma once

class IWidget;
class IDirector
{
public:
	virtual ~IDirector() { };

public:
	virtual void WidgetChanged(IWidget* widget) = 0;
	virtual void CreateWidgets() = 0;
};