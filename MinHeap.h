#pragma once

typedef struct HeapNode
{
	int weight, vertex, index;
}HeapNode;

class MinHeap
{
private:
	HeapNode* node;
	int maxSize;
	int heapSize;
	bool allocated;

	HeapNode** twinsArray ; // array of pointers to heapNode

	static int Left(int index);
	static int Right(int index);
	static int Parent(int index);

	void fixHeap(int index);
	void swap(HeapNode& n1, HeapNode& n2);

public:

	MinHeap();
	int getHeapSize()const { return heapSize; };
	~MinHeap();
	bool isEmpty() { return heapSize == 0; }
	void buildHeap(int n, int arr[]);

	HeapNode Min();
	int DeleteMin();
	void decreaseKey(int v, int weight);

	void print();
};