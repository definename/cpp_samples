#include "pch.h"
#include "Timer.h"
#include "IObserver.h"

Timer::Timer()
{ }

Timer::~Timer()
{
	observers_.clear();
}

boost::uuids::uuid Timer::Attach(ObserverPtr observer)
{
	boost::uuids::uuid id = boost::uuids::random_generator()();
	observers_.insert(std::make_pair(id, observer));
	return id;
}

void Timer::Dettach(const boost::uuids::uuid& id)
{
	observers_.erase(id);
}

void Timer::Notify()
{
	boost::posix_time::ptime time = boost::posix_time::second_clock::local_time();
	for (const ObserverMap::value_type& val : observers_)
	{
		val.second->Update(boost::posix_time::to_simple_wstring(time));
	}
}