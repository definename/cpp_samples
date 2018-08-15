#include "pch.h"
#include "logger.h"

bool Logger::isInitialized_ = false;
const std::string Logger::logName_ = "log.txt";
std::ofstream Logger::outStream_;

const std::string Logger::logLevelDebug_ = "DEBUG: ";
const std::string Logger::logLevelInfo_ = "INFO: ";
const std::string Logger::logLevelError_ = "ERROR: ";

void Logger::Log(const std::string& message, const std::string& logLevel)
{
	if (!isInitialized_)
		Init();
	
	outStream_ << logLevel << message << std::endl;
}

void Logger::Init()
{
	if (!isInitialized_)
		outStream_.open(logName_, std::ios::app);

	if (outStream_.fail())
	{
		std::cout << "Unable to initialize log file" << std::endl;
		return;
	}

	isInitialized_ = true;
}

void Logger::TearDown()
{
	if (isInitialized_)
	{
		outStream_.close();
		isInitialized_ = false;
	}
}