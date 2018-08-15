#pragma once

template <typename V, typename R>
std::ostream& operator << (std::ostream& s, const std::chrono::duration<V, R>& d)
{
	s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
	return s;
}

namespace utils
{

//! Converts system time point into calendar time.
std::string TimePointAsString(std::chrono::system_clock::time_point const& tp);
//! Converts calendar time into time point by system clock.
std::chrono::system_clock::time_point MakeTimePoint(
	int year, int mon, int day, int hour, int min, int sec = 0);
//! Creates time stamp from given date time.
template<typename TimeType>
std::string MakeTimeStamp(int year, int mon, int day, int hour, int min, int sec/* = 0*/)
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

    return std::to_string(std::chrono::duration_cast<TimeType>(
        std::chrono::system_clock::from_time_t(tt).time_since_epoch()).count());
}
//! Returns actual timestamp.
template<typename TimeType>
std::string MakeTimeStamp()
{
    return std::to_string(std::chrono::duration_cast<TimeType>(
        std::chrono::system_clock::now().time_since_epoch()).count());
}


} // namespace utils