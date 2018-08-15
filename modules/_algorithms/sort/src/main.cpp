#include "pch.h"
#include "Sorter.h"

void CheckSpeed(Sorter& s);

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		Sorter s;
		//! Check algorithm.
		s.InsertionSort(true);
		s.BinaryInsertionSort(true);
		s.RecursionBinaryInsertionSort(true);

		//! Check algorithm's speed.
		_tcout << _T("\tArray size: 100000") << std::endl;
		s.SetSize(100000);
		CheckSpeed(s);
		_tcout << _T("\tArray size: 1000000") << std::endl;
		s.SetSize(1000000);
		CheckSpeed(s);
		_tcout << _T("\tArray size: 2000000") << std::endl;
		s.SetSize(2000000);
		CheckSpeed(s);
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}
}

void CheckSpeed(Sorter& s)
{
	std::vector<std::thread> threads;
	threads.emplace_back(&Sorter::InsertionSort, s, false);
	threads.emplace_back(&Sorter::RecursionBinaryInsertionSort, s, false);
	threads.emplace_back(std::bind(&Sorter::BinaryInsertionSort, s, false));

	std::for_each(threads.begin(), threads.end(), [](std::thread& t) { t.join(); });
}
