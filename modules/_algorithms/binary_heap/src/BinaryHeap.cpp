#include "pch.h"
#include "BinaryHeap.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the BinaryHeap class.
//

BinaryHeap::BinaryHeap()
{ }

BinaryHeap::~BinaryHeap()
{ }

void BinaryHeap::Add(const int& val)
{
	arr_.push_back(val);

	int i = GetSize() - 1;
	int parent = (i - 1) / 2;

	while (i > 0 && arr_[parent] < arr_[i])
	{
		int temp = arr_[i];
		arr_[i] = arr_[parent];
		arr_[parent] = temp;

		i = parent;
		parent = (i - 1) / 2;
	}
}

void BinaryHeap::BuildHeap(const std::vector<int>& arr)
{
	for (const int& val : arr)
	{
		Add(val);
	}
}

void BinaryHeap::Heapify(int i)
{
	int leftChild;
	int rightChild;
	int largestChild;

	for (;;)
	{
		leftChild = 2 * i + 1;
		rightChild = 2 * i + 2;
		largestChild = i;

		if (leftChild < GetSize() && arr_[leftChild] > arr_[largestChild])
		{
			largestChild = leftChild;
		}

		if (rightChild < GetSize() && arr_[rightChild] > arr_[largestChild])
		{
			largestChild = rightChild;
		}

		if (largestChild == i)
		{
			break;
		}

		int temp = arr_[i];
		arr_[i] = arr_[largestChild];
		arr_[largestChild] = temp;
		i = largestChild;
	}
}

void BinaryHeap::HeapSort(std::vector<int>& arr)
{
	BuildHeap(arr);

	for (int i = GetSize() - 1; i >= 0; i--)
	{
		arr[i] = GetMax();
		Heapify(0);
	}
}

int BinaryHeap::GetMax()
{
	int result = arr_[0];

	arr_[0] = arr_[GetSize() - 1];
	arr_.pop_back();

	return result;
}

size_t BinaryHeap::GetSize() const
{
	return arr_.size();
}