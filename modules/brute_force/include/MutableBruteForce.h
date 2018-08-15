#pragma once

class MutableBruteForce
{
public:
	MutableBruteForce();
	~MutableBruteForce();

public:
	void DoBruteForce() const;
	mutable int val_;
};