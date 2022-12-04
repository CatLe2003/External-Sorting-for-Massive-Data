#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Book
{
	string id;
	string other_info;
};
struct HeapNode
{
	Book element;
	int index;
};

//Create the min-heap to store the first element of Sketch Files
class MinHeap
{
private:
	HeapNode* _arr;
	int _size;
public:
	MinHeap(HeapNode*, int);
	void heapify(int);
	int getLeft(int index)
	{
		return (2 * index + 1);
	}
	int getRight(int index)
	{
		return (2 * index + 2);
	}
	HeapNode getMin()
	{
		return _arr[0];
	}
	void replaceMin(HeapNode x)
	{
		_arr[0] = x;
		heapify(0);
	}
	void printHeap(int pos);
};

void printBook(Book a);
void printNodetoFile(ofstream& ofs, HeapNode a);
HeapNode createHeapNode(Book a, int index);
