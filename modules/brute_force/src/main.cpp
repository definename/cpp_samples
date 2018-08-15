#include "pch.h"
#include "BruteForce.h"
#include "MutableBruteForce.h"

void _tmain(int argc, TCHAR* argv[])
{
	//! const_cast example.
	BruteForce bf;
	bf.DoBruteForce();
	_tcout << "BruteForce: " << bf.val_ << std::endl;

	//! mutable example.
	const MutableBruteForce mbf;
	mbf.DoBruteForce();
	_tcout << "MutableBruteForce: " << mbf.val_ << std::endl;
}