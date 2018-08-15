#include "pch.h"
#include "Singleton.h"

Singleton* Singleton::inst_ = nullptr;

void Singleton::Destroy()
{
	delete inst_;
	inst_ = nullptr;
}

Singleton* Singleton::Instance()
{
	if (!inst_)
		inst_ = new Singleton();

	return inst_;
}

void Singleton::DoSomething() const
{
	std::cout << "Do something..." << std::endl;
}