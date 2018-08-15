#pragma once

// Forward declaration.
struct Impl;

class Widget
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Widget();
	//! Destructor.
	~Widget();

	//
	// Public interface.
	//
public:
	//! Returns gadget name.
	std::string GetGadgetName() const;

	//
	// Private data members.
	//
private:
	//! Impl pointer.
	std::shared_ptr<Impl> impl_;
};