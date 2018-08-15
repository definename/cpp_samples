#include "pch.h"
#include "Sorter.h"

Sorter::Sorter()
	: size_(10)
{
	srand(time(NULL));
}

Sorter::~Sorter()
{ }

void Sorter::DoInsertionSort(int *arr)
{
	//! �������� �� ������� �������� size_.
	for (int i = 1; i != size_; ++i)
	{
		//! ����������� �������.
		int temp = arr[i];
		int j = i - 1;
		//! ����� ����������� ����� �������.
		while (j != -1 && (temp < arr[j]))
		{
			//! ����������� ������������� �������� ������.
			arr[j + 1] = arr[j];
			j--;
		}
		//! ������� ��������� �������������� �����.
		arr[j + 1] = temp;
	}
}

void Sorter::DoBinaryInsertionSort(int *arr)
{
	//! �������� �� ������� �������� size_.
	for (int i = 1; i != size_; ++i)
	{
		//! ����������� �������.
		int temp = arr[i];
		//! ����� ������� ������� �������.
		int left = 0;
		//! ������ ������� ������� �������.
		int right = i - 1;

		while (left <= right)
		{
			//! ������ �������� ���������� ������� �������.
			int j = (left + right) / 2;

			if (temp < arr[j])
				right = j - 1;
			else
				left = j + 1;
		}
		//! �����: ����� ����� �������.

		//! �������� ��������, ������������� ������ ����� �������.
		for (int k = i - 1; k >= left; k--)
			arr[k + 1] = arr[k];

		//! ��������� ������� � ������ �����.
		arr[left] = temp;
	}
}

void Sorter::DoRecursionBinaryInsertionSort(int *arr, int i /*= 1*/)
{
	//! ������� ������ �� ��������.
	if (i >= size_)
		return;

	//! ����������� �������.
	int temp = arr[i];
	//! ����� ������� ������� �������.
	int left = 0;
	//! ������ ������� ������� �������.
	int right = i - 1;

	while (left <= right)
	{
		//! ������ �������� ���������� ������� �������.
		int j = (left + right) / 2;

		if (temp < arr[j])
			right = j - 1;
		else
			left = j + 1;
	}
	//! �����: ����� ����� �������.

	//! �������� ��������, ������������� ������ ����� �������.
	for (int k = i - 1; k >= left; k--)
		arr[k + 1] = arr[k];

	//! ��������� ������� � ������ �����.
	arr[left] = temp;
	//! ����������� �������� �� ������� �������� size_.
	DoRecursionBinaryInsertionSort(arr, i + 1);
}

void Sorter::BinaryInsertionSort(bool print)
{
	//! Allocate and initialize array.
	int *arr(new int[size_]);
	Fill(arr, _T("BinaryInsertion"));

	if (print)
	{
		_tcout << _T("origin:") << std::endl;
		Print(arr);
	}

	//! Do sort.
	clock_t t = clock();
	DoBinaryInsertionSort(arr);
	t = clock() - t;

	if (print)
	{
		_tcout << _T("Result:") << std::endl;
		Print(arr);
	}
	else
	{
		_tcout << "*** BinaryInsertion *** sort took time: " <<
			static_cast<float>(t) / CLOCKS_PER_SEC << _T(" seconds") << std::endl;
	}

	delete[] arr;
}

void Sorter::Fill(int *arr, const TCHAR name[])
{
	for (int i = 0; i != size_; ++i)
	{
		arr[i] = rand() % 100 + 1;
	}
	_tcout << name << _T(" array has been *** filled!") << std::endl;
}

void Sorter::InsertionSort(bool print)
{
	//! Allocate and initialize array.
	int *arr(new int[size_]);
	Fill(arr, _T("Insertion"));

	if (print)
	{
		_tcout << _T("origin:") << std::endl;
		Print(arr);
	}

	//! Do sort.
	clock_t t = clock();
	DoInsertionSort(arr);
	t = clock() - t;

	if (print)
	{
		_tcout << _T("Result:") << std::endl;
		Print(arr);
	}
	else
	{
		_tcout << "*** Insertion *** sort took time: " <<
			static_cast<float>(t) / CLOCKS_PER_SEC << _T(" seconds") << std::endl;
	}

	delete[] arr;
}

void Sorter::Print(int * arr)
{
	for (int i = 0; i != size_; ++i)
	{
		_tcout << arr[i] << " ";
	}
	_tcout << std::endl;
	_tcout << std::endl;
}

void Sorter::RecursionBinaryInsertionSort(bool print)
{
	//! Allocate and initialize array.
	int *arr(new int[size_]);
	Fill(arr, _T("RecursionBinaryInsertion"));

	if (print)
	{
		_tcout << _T("origin:") << std::endl;
		Print(arr);
	}

	//! Do sort.
	clock_t t = clock();
	DoRecursionBinaryInsertionSort(arr);
	t = clock() - t;

	if (print)
	{
		_tcout << _T("Result:") << std::endl;
		Print(arr);
	}
	else
	{
		_tcout << "*** RecursionBinaryInsertion *** sort took time: " <<
			static_cast<float>(t) / CLOCKS_PER_SEC << _T(" seconds") << std::endl;
	}

	delete[] arr;
}

void Sorter::SetSize(const int size)
{
	size_ = size;
}