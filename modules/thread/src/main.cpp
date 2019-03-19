#include "pch.h"

int main(int argc, char* argv[])
{
	logger::InitializeLog("console");
	try
	{
		logger::log->info("{}", "thread");
	}
	catch (spdlog::spdlog_ex& e)
	{
		std::cerr << "spdlog error occurred: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		logger::log->error("Error occurred {}", e.what());
	}
	logger::UninitializeLog();

	return 0;
}