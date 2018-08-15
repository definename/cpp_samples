#pragma once

class Logger
{
	//
	// Public members.
	//
public:
	//! Debug log level.
	static const std::string logLevelDebug_;
	//! Info log level.
	static const std::string logLevelInfo_;
	//! Error log level.
	static const std::string logLevelError_;

	//
	// Public interface.
	//
public:
	//! Writes message to log file.
	static void Log(const std::string& message, const std::string& logLevel);
	//! Closes log file.
	static void TearDown();

	//
	// Protected interface.
	//
protected:
	//! Initializes log.
	static void Init();

	//
	// Protected data members.
	//
protected:
	//! Is log initialized.
	static bool isInitialized_;
	//! Log name.
	static const std::string logName_;
	//! Log stream.
	static std::ofstream outStream_;

	//
	// Construction and destruction.
	//
private:
	//! Constructor.
	Logger() {};
};