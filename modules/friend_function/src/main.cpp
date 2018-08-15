#include "pch.h"
#include "ClassA.h"
#include "ClassB.h"

void _tmain(int argc, TCHAR* argv[])
{
	ClassA objectA;
	ClassB objectB;

	_tcout << objectA * objectB << std::endl;
	_tcout << objectB * objectA << std::endl;
}