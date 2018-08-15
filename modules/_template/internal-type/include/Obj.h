#pragma once

template<typename T>
class Obj
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Obj()
		: status_(Status::On)
	{ }

	//
	// Public types.
	//
public:
	//! Status type.
	enum class Status
	{
		On,
		Off
	};

	//
	// Public interface.
	//
public:
	//! Returns status.
	Status GetStatus() const;

	//
	// Private data members.
	//
private:
	//! Status.
	Status status_;
};

template<typename T>
typename Obj<T>::Status Obj<T>::GetStatus() const
{
	return status_;
}