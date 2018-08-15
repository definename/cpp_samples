#include "pch.h"
#include "WidgetImpl2.h"
#include "IDirector.h"

WidgetImpl2::WidgetImpl2(IDirector* director, const int& id)
	: IWidget(director)
	, id_(id)
{
	// Do this from other place.
	Handler();
}

WidgetImpl2::~WidgetImpl2()
{ }

int WidgetImpl2::GetId()
{
	return id_;
}

void WidgetImpl2::Handler()
{
	//! Do something.
	Changed();
}