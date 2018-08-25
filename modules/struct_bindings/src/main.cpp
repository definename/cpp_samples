#include "pch.h"

struct ToBind
{
	std::string name_;
	int number_;
};

int main(int argc, char* argv[], char* env[])
{
	int code = 0;
	try
	{
		logger::InitializeLog("console");

		auto func = []() -> ToBind
		{
			ToBind toBind;

			toBind.name_ = "Vasya";
			toBind.number_ = 1;

			return toBind;
		};

		auto[name, number] = func();

		logger::log->info("Name: {} Number: {}", name, number);

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