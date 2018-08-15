#include "pch.h"
#include "WidgetImpl1.h"
#include "IDirector.h"

WidgetImpl1::WidgetImpl1(IDirector* director, const int& id)
	: IWidget(director)
	, id_(id)
{
	// Do this from other place.
	Handler();
}

WidgetImpl1::~WidgetImpl1()
{ }

int WidgetImpl1::GetId()
{
	return id_;
}

void WidgetImpl1::Handler()
{
	//! Do something.
	Changed();
}