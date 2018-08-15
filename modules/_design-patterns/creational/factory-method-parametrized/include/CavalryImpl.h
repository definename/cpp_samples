#pragma once
#include "Warrior.h"

class CavalryImpl : public Warrior
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	CavalryImpl() = default;
	//! Destructor.
	~CavalryImpl() = default;

	//
	// Public interface.
	//
public:
	//! Warrior info.
	void Info();
};