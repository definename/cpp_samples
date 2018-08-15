#pragma once


class Singleton
{
	//
	// Construction and destruction.
	//
protected:
	//! Constructor.
	Singleton() = default;
public:
	//! Destructor.
	~Singleton() = default;

	//
	// Public interface.
	//
public:
	//! Destroys singleton instance.
	static void Destroy();
	//! Returns singleton instance.
	static Singleton* Instance();
	//! Does something.
	void DoSomething() const;

	//
	// Private data members.
	//
private:
	//! Singleton instance.
	static Singleton* inst_;
};