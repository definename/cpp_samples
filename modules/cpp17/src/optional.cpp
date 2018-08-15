#include "pch.h"
#include "cpp17/optional.h"

namespace cpp17
{

void TestOptional()
{
	std::optional<std::string> name;
	if (!name)
	{
		logger::log->info("Name was not set!!");
	}

	name = "Oleh";
	logger::log->info("Name: {}", name.value());
}

} // namespace cpp17