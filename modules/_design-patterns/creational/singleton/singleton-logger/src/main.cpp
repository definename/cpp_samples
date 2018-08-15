#include "pch.h"
#include "logger.h"
#include "trueLogger.h"

int main()
{
	// Simple singleton. log.txt file.
	std::cout << "Simple log example..." << std::endl;
	Logger::Log("Simple log successfully initialized", Logger::logLevelInfo_);
	for (int i = 0; i != 10; i++)
	{
		Logger::Log("Do something...", Logger::logLevelDebug_);
	}
	Logger::TearDown();

	// True singleton. trueLog.txt file.
	std::cout << "True log example..." << std::endl;
	TrueLogger& instance = TrueLogger::Instance();
	instance.Log("True log successfully initialized", TrueLogger::logLevelInfo_);
	for (int i = 0; i != 10; i++)
	{
		instance.Log("Do something...", TrueLogger::logLevelDebug_);
	}

	return 0;
}