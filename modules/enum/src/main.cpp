#include "pch.h"

enum Type
{
	SubType = 100,
	SubType1 = 101,
};

int main(int argc, char* argv[])
{
	int code = 0;
	try
	{
		logger::InitializeLog("console");

		Type type;
		type = Type::SubType1;
		logger::log->info("{}", type);

		logger::UninitializeLog();
	}
	catch (const spdlog::spdlog_ex& e)
	{
		code = 1;
		std::cerr << "spdlog error occurred: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		code = 2;
		logger::log->error("Error occurred: {}", e.what());
	}

	return 0;
}