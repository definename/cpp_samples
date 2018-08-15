#include "pch.h"
#include "CavalryCreator.h"
#include "CavalryImpl.h"

CavalryCreator::CavalryCreator()
{ }

CavalryCreator::~CavalryCreator()
{ }

IWarrior* CavalryCreator::CreateWarrior()
{
	return new CavalryImpl;
}