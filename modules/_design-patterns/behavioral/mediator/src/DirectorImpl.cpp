#include "pch.h"
#include "DirectorImpl.h"
#include "WidgetImpl1.h"
#include "WidgetImpl2.h"

DirectorImpl::DirectorImpl()
{ }

DirectorImpl::~DirectorImpl()
{
	delete widget1_;
	delete widget2_;
}

void DirectorImpl::WidgetChanged(IWidget* widget)
{
	_tcout << _T("Widget with id has been signaled: ") << widget->GetId() << std::endl;
}

void DirectorImpl::CreateWidgets()
{
	widget1_ = new WidgetImpl1(this, 1);
	widget2_ = new WidgetImpl2(this, 2);
}
