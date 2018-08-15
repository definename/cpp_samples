#pragma once

class Sorter
{
	//! Construction and destruction.
public:
	//! Constructor.
	Sorter();
	//! Destructor.
	~Sorter();

	//! Public interface.
public:
	//! Represents binary insertion sort algorithm.
	void BinaryInsertionSort(bool print);
	//! Represents straight insertion sort algorithm.
	void InsertionSort(bool print);
	//! Represents recursion binary insertion sort algorithm.
	void RecursionBinaryInsertionSort(bool print);
	//! Sets array's size.
	void SetSize(const int size);

	//! Private interface.
private:
	//! Do Represents straight insertion sort algorithm.
	void DoInsertionSort(int *arr);
	//! Do Represents binary insertion sort algorithm.
	void DoBinaryInsertionSort(int *arr);
	//! Do Represents recursion binary insertion sort algorithm.
	void DoRecursionBinaryInsertionSort(int *arr, int i = 1);
	//! Fills array.
	void Fill(int *arr, const TCHAR name[]);
	//! Prints array.
	void Print(int * arr);

private:
	//! Array's size.
	int size_;
};