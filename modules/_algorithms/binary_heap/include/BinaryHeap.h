#pragma once

//////////////////////////////////////////////////////////////////////////
// Interface of the BinaryHeap class.
//

class BinaryHeap
{
	//
	//! Construction and destruction.
	//
public:
	//! Constructor.
	BinaryHeap();
	//! Destructor.
	~BinaryHeap();

	//
	//! Public interface.
	//
public:
	//! Adds to the heap.
	void Add(const int& val);
	//! Builds heap.
	void BuildHeap(const std::vector<int>& arr);
	//! Returns max element.
	int GetMax();
	//! Returns size.
	size_t GetSize() const;
	//! Heapify heap.
	void Heapify(int i);
	//! Sorts heap.
	void HeapSort(std::vector<int>& arr);

private:
	//! Heap.
	std::vector<int> arr_;
};