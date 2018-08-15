#include "pch.h"
#include "InfantryCreator.h"
#include "InfantryImpl.h"

InfantryCreator::InfantryCreator()
{ }

InfantryCreator::~InfantryCreator()
{ }

IWarrior* InfantryCreator::CreateWarrior()
{
	return new InfantryImpl;
}