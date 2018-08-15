#pragma once

namespace logger
{

//! Logger forward declaration.
extern std::shared_ptr<spdlog::logger> log;
//! Initializes logging.
void InitializeLog(const std::string& logname);
//! Uninitializes logging.
void UninitializeLog();

}