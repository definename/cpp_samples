#include "pch.h"
#include "Widget.h"
#include "Impl.h"
#include "Gadget.h"

Widget::Widget()
	: impl_(std::make_shared<Impl>())
{ }

Widget::~Widget()
{ }

std::string Widget::GetGadgetName() const
{
	return impl_->gadget_.name_;
}