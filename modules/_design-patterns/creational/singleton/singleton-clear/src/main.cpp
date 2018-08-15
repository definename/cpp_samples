#include "pch.h"
#include "Singleton.h"

int main()
{
	Singleton::Instance()->DoSomething();

	Singleton::Instance()->Destroy();

	return 0;
}