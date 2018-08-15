#pragma once

#include "ISubject.h"
class Timer : public ISubject
{
public:
	Timer();
	~Timer();

public:
	typedef std::map<boost::uuids::uuid, ObserverPtr> ObserverMap;

public:
	boost::uuids::uuid Attach(ObserverPtr observer);
	void Dettach(const boost::uuids::uuid& id);
	void Notify();

private:
	ObserverMap observers_;
};