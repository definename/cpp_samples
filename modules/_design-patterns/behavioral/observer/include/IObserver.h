#pragma once

class IObserver
{
public:
	virtual ~IObserver() { }

public:
	virtual void Update(const _tstring& time) = 0;
};