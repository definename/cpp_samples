#include "pch.h"
#include "Logger.h"

namespace logger
{

std::shared_ptr<spdlog::logger> log = nullptr;

void InitializeLog(const std::string& logname)
{
	std::vector<spdlog::sink_ptr> sinks;
	sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_mt>());

	log = std::make_shared<spdlog::logger>(logname, sinks.begin(), sinks.end());
	log->set_level(spdlog::level::trace);

	spdlog::register_logger(log);
}

void UninitializeLog()
{
	spdlog::drop_all();
}

}