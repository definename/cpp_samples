#pragma once

#include "IWidget.h"
class IDirector;
class WidgetImpl2 : public IWidget
{
public:
	WidgetImpl2(IDirector* director, const int& id);
	~WidgetImpl2();

public:
	int GetId();
	void Handler();

private:
	int id_;
};