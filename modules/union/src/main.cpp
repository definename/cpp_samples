#include "pch.h"
#include <filesystem>

union UTest
{
	double double1_;
	double double2_;
};

int main(int argc, char* argv[])
{
	int code = 0;
	try
	{
		logger::InitializeLog("console");

		union UTest var;

		var.double1_ = 999999;
		logger::log->info("Var: {}", var.double1_);
		var.double2_ = 10;
		logger::log->info("Var: {}", var.double1_);

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