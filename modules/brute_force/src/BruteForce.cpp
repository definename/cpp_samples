#include "pch.h"
#include "BruteForce.h"

BruteForce::BruteForce() { }

BruteForce::~BruteForce() { }

void BruteForce::DoBruteForce() const
{
	BruteForce* bf = const_cast<BruteForce*>(this);
	bf->val_ = 200;
}