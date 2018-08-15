#pragma once

#include "Types.h"

class ISubject
{
public:
	virtual ~ISubject() { }

public:
	virtual boost::uuids::uuid Attach(ObserverPtr observer) = 0;
	virtual void Dettach(const boost::uuids::uuid& id) = 0;
	virtual void Notify() = 0;
};