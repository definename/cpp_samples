#pragma once

#include "IDirector.h"
class IWidget
{
public:
	IWidget(IDirector* director)
		: director_(director)
	{ }
	virtual ~IWidget() { }

public:
	virtual void Changed() { director_->WidgetChanged(this); };
	virtual void Handler() = 0;
	virtual int GetId() = 0;

private:
	IDirector* director_;
};