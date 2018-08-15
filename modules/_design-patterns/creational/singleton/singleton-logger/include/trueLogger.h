#pragma once

class TrueLogger
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
	//!
	static TrueLogger& Instance();
	//! Writes message to log file.
	static void Log(const std::string& message, const std::string& logLevel);

	//
	// Protected data members.
	//
protected:
	//! Logger instance.
	static TrueLogger instance_;
	//! Log name.
	static const std::string logName_;
	//! Log stream.
	static std::ofstream outStream_;

	//
	// Construction and destruction.
	//
private:
	//! Constructor.
	TrueLogger();
	//! Destructor.
	~TrueLogger();
};