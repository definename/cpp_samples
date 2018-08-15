#include "pch.h"
#include "trueLogger.h"

const std::string TrueLogger::logName_ = "trueLog.txt";
std::ofstream TrueLogger::outStream_;

const std::string TrueLogger::logLevelDebug_ = "DEBUG: ";
const std::string TrueLogger::logLevelInfo_ = "INFO: ";
const std::string TrueLogger::logLevelError_ = "ERROR: ";

TrueLogger TrueLogger::instance_;

TrueLogger::TrueLogger()
{
	outStream_.open(logName_, std::ios::app);

	if (outStream_.fail())
		std::cout << "Unable to initialize true log file" << std::endl;
}

TrueLogger::~TrueLogger()
{
	outStream_.close();
}

void TrueLogger::Log(const std::string& message, const std::string& logLevel)
{
	outStream_ << logLevel << message << std::endl;
}

TrueLogger& TrueLogger::Instance()
{
	return instance_;
}