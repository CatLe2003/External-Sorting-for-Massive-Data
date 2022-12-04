#include "Heap.h"
void printBook(Book a)
{
	cout << a.id << " ";
}
void printNodetoFile(ofstream& ofs, HeapNode a)
{
	ofs << a.element.id << "," << a.element.other_info << endl;
}
HeapNode createHeapNode(Book a, int index)
{
	HeapNode result;
	result.element = a;
	result.index = index;

	return result;
}
MinHeap::MinHeap(HeapNode* a, int size)
{
	_size = size;
	_arr = a;
	int i = (_size - 1) / 2;
	while (i >= 0)
	{
		heapify(i);
		--i;
	}

}
void MinHeap::heapify(int i)
{
	int left = getLeft(i);
	int right = getRight(i);
	int smallest = i;
	if (left < _size && _arr[left].element.id < _arr[i].element.id)
	{
		smallest = left;
	}
	if (right < _size && _arr[right].element.id < _arr[smallest].element.id)
	{
		smallest = right;
	}
	if (smallest != i)
	{
		swap(_arr[i], _arr[smallest]);
		heapify(smallest);
	}
}
void MinHeap::printHeap(int position = 0)
{
	if (position >= _size)
		return;
	printBook(_arr[position].element);

	printHeap(getLeft(position));
	printHeap(getRight(position));
}