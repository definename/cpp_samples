#include "pch.h"
#include "ArchersCreator.h"
#include "ArchersImpl.h"

ArchersCreator::ArchersCreator()
{ }

ArchersCreator::~ArchersCreator()
{ }

IWarrior* ArchersCreator::CreateWarrior()
{
	return new ArchersImpl;
}