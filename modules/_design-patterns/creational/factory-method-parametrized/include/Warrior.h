#pragma once
#include "Types.h"

class Warrior
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Warrior() = default;
	//! Destructor.
	virtual ~Warrior() = default;

	//
	// Public types.
	//
public:
	//! Warrior types.
	enum class Type {
		ARCHER,
		CAVALRY,
		INFANTRY
	};

	//
	// Public interface.
	//
public:
	//! Warrior info.
	virtual void Info() = 0;
	//! Factory method.
	static types::WarriorPtr CreateWarrior(const Type& type);
};