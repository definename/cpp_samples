#pragma once

class Gadget
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Gadget() = default;
	//! Destructor.
	~Gadget() = default;

	//
	// Public data members.
	//
public:
	//! Name.
	const std::string name_ = "Gadget";
};