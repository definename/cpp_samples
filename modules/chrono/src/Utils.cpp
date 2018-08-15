#include "pch.h"
#include "Utils.h"

namespace utils
{

std::chrono::system_clock::time_point MakeTimePoint(
	int year, int mon, int day, int hour, int min, int sec/* = 0*/)
{
	struct std::tm t;
	t.tm_sec = sec;
	t.tm_min = min;
	t.tm_hour = hour;
	t.tm_mday = day;
	t.tm_mon = mon - 1;
	t.tm_year = year - 1900;
	t.tm_isdst = -1;

	std::time_t tt = std::mktime(&t);
	if (tt == -1)
		throw std::runtime_error("No valid system time");

	return std::chrono::system_clock::from_time_t(tt);
}

std::string TimePointAsString(std::chrono::system_clock::time_point const& tp)
{
	std::time_t tt;
	tt = std::chrono::system_clock::to_time_t(tp);
	return ctime(&tt); // Localtime time
	//return std::asctime(std::localtime(&tt)); // The same as ctime(&tt)
	//return std::asctime(std::gmtime(&tt)); // UTC time
}


} // namespace utils