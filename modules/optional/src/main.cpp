#include "pch.h"

int main(int argc, char* argv[], char* env[])
{
	int code = 0;
	try
	{
		logger::InitializeLog("console");

		std::optional<std::string> name;
		if (!name)
		{
			logger::log->info("Name was not set!!");
		}

		name = "Oleh";
		logger::log->info("Name: {}", name.value());

		logger::UninitializeLog();
	}
	catch (const spdlog::spdlog_ex& e)
	{
		std::cerr << "spdlog error occurred: " << e.what() << std::endl;
		code = 1;
	}
	catch (const std::exception& e)
	{
		logger::log->error("Error occurred: {}", e.what());
		code = 2;
	}

	return 0;
}