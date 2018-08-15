#include "pch.h"

int main(int argc, char* argv[], char* env[])
{
	try
	{
		logger::InitializeLog("console");

		cpp17::TestStructuredBinding();
		cpp17::TestOptional();

		logger::UninitializeLog();
	}
	catch (const spdlog::spdlog_ex& e)
	{
		std::cerr << "spdlog error occurred: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		logger::log->error("Error occurred: {}", e.what());
	}
	return 0;
}