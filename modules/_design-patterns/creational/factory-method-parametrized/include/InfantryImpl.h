#pragma once
#include "Warrior.h"

class InfantryImpl : public Warrior
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	InfantryImpl() = default;
	//! Destructor.
	~InfantryImpl() = default;

	//
	// Public interface.
	//
public:
	//! Warrior info.
	void Info();
};