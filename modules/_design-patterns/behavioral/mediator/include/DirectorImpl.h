#pragma once

class WidgetImpl1;
class WidgetImpl2;
#include "IDirector.h"
class DirectorImpl : public IDirector
{
public:
	DirectorImpl();
	~DirectorImpl();

public:
	void WidgetChanged(IWidget* widget);
	void CreateWidgets();


private:
	WidgetImpl1* widget1_;
	WidgetImpl2* widget2_;
};