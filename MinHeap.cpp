#include"MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap()
{
	node = nullptr;
	twinsArray = nullptr;
	maxSize = 0;
	heapSize = 0;
	allocated = false;
}
MinHeap::~MinHeap()
{
	delete[] node;
	node = nullptr;

	//delete twinsArray
}


int MinHeap::Left(int index)
{
	return (2 * index );

}


int MinHeap::Right(int index)
{
	return (2 * index + 1);

}
int MinHeap::Parent(int index)
{
	return ((index ) / 2);

}

void MinHeap::fixHeap(int index)
{
	int min;
	int left = Left(index);
	int right = Right(index);


	if ((left < heapSize) && (node[left].weight < node[index].weight))
	{
		min = left;
	}
	else
		min = index;

	if ((right < heapSize) && (node[right].weight < node[min].weight))
	{
		min = right;
	}
	if (min != index)
	{
		swap(node[index], node[min]);
		fixHeap(min);
	}


}

void MinHeap::swap(HeapNode& n1, HeapNode& n2)
{
	HeapNode temp;
	int vertex = node[n1.index].vertex;
	node[n1.index].vertex = node[n2.index].vertex;
	node[n2.index].vertex = vertex;


	int weight = node[n1.index].weight;
	node[n1.index].weight = node[n2.index].weight;
	node[n2.index].weight = weight;

	HeapNode* tempP = twinsArray[n1.vertex];
	twinsArray[n1.vertex] = twinsArray[n2.vertex];
	twinsArray[n2.vertex] = tempP;
}

HeapNode MinHeap::Min()
{
	return node[1];

}

int MinHeap::DeleteMin()
{
	if (heapSize < 1)
	{
		cout << "Error" << endl;
		exit(1);
	}

	HeapNode min = node[1];
	heapSize--;
	node[heapSize + 1].index = 1;
	node[1] = node[heapSize+1];
	
	fixHeap(1);
	return min.vertex;

}
void MinHeap::buildHeap(int n, int arr[])
{
	heapSize = 0;
	node = new HeapNode[n + 1]();
	twinsArray = new HeapNode * [n + 1]();
	for (int i = 1; i <= n; i++)
	{
		twinsArray[i] = &node[i];
		node[i].vertex = i;
		node[i].index = i;
		node[i].weight = arr[i];
		heapSize++;
	}
	maxSize = n;

	int startIdx = (n / 2) ;
	
	for(int i = startIdx; i > 0; i--)
	{
		fixHeap(i);
	}
	
}

void MinHeap::print()
{
	for (int i = 1; i <= heapSize; i++)
	{
		cout << node[i].vertex << ' ' << node[i].weight << endl;
	}
	
}

void MinHeap::decreaseKey(int v, int weight)
{

	HeapNode* curr = twinsArray[v];

	curr->weight = weight;

	int index;
	index = curr->index;

	while (index != 1 && curr->weight < node[Parent(index)].weight)
	{

		swap(*curr, node[Parent(index)]);
		
		curr = twinsArray[v];
	
		index = curr->index;
	}
}