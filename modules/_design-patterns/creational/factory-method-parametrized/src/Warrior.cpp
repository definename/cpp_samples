#include "pch.h"
#include "ArchersImpl.h"
#include "CavalryImpl.h"
#include "InfantryImpl.h"
#include "Warrior.h"

types::WarriorPtr Warrior::CreateWarrior(const Type& type)
{
	if (type == Type::ARCHER)
		return std::make_unique<ArchersImpl>();
	else if (type == Type::CAVALRY)
		return std::make_unique<CavalryImpl>();
	else if (type == Type::INFANTRY)
		return std::make_unique<InfantryImpl>();
	return nullptr;
}