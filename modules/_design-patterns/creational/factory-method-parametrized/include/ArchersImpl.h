#pragma once
#include "Warrior.h"

class ArchersImpl : public Warrior
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	ArchersImpl() = default;
	//! Destructor.
	~ArchersImpl() = default;

	//
	// Public interface.
	//
public:
	//! Warrior info.
	void Info();
};