#pragma once

#include "IWidget.h"
class IDirector;
class WidgetImpl1 : public IWidget
{
public:
	WidgetImpl1(IDirector* director, const int& id);
	~WidgetImpl1();

public:
	int GetId();
	void Handler();

private:
	int id_;
};