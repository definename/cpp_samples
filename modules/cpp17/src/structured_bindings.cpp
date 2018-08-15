#include "pch.h"
#include "cpp17/structured_bindings.h"

namespace cpp17
{

void TestStructuredBinding()
{
	auto func = []() -> ToBind 
	{
		ToBind toBind;

		toBind.name_ = "Vasya";
		toBind.number_ = 4;

		return toBind;
	};

	auto[name, number] = func();

	logger::log->info("Name: {} Number: {}", name, number);
}

} // namespace cpp17