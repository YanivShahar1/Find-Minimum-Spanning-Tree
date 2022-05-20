#include "prim.h"
#include"UnDirectedGraph.h"
#include"MinHeap.h"

int prim(UnDirectedGraph& g)
{
	MinHeap minHeap;
	int numOfVertices = g.getSize();
	bool* inT = new bool[numOfVertices + 1];
	int* min = new int[numOfVertices + 1 ];
	int* parents = new int[numOfVertices + 1];
	initArrays(inT, min, parents, numOfVertices);
	minHeap.buildHeap(numOfVertices, min);
	while (!minHeap.isEmpty())
	{
		int u = minHeap.DeleteMin();
		inT[u] = true;
		
		const List* list = g.getAdjList(u);
		Node* curr = list->getHead();
		while (curr != nullptr)
		{	
			int currVertex = curr->vertex;
			int currWeight = findWeight(u, currVertex, g);
			if (inT[currVertex] == false && currWeight < min[currVertex])
			{
				min[currVertex] = currWeight;
				parents[currVertex] = u;
				minHeap.decreaseKey(currVertex, min[currVertex]);
			}

			curr = curr->next;
		}

	}
	int weightsum = 0;
	for (int i = 1; i <= g.getNumOfVertices(); i++)
	{
		weightsum += min[i];
	}
	delete[]inT;
	delete[]min;
	delete[]parents;
	return weightsum;
}

int findWeight(int u, int v, UnDirectedGraph& g)
{
	bool found = false;
	int res = 0;
	const List* list = g.getAdjList(u);
	Node* curr = list->getHead();
	
	while (!found && curr!=nullptr)
	{
		if (curr->vertex == v)
		{
			res = curr->weight;
			found = true;
		}
		else
		{
			curr = curr->next;
		}
	}
	if (!found)
	{
		cout << "cant find edge: " << ' ' << u << ' ' << v << endl;
		exit(1);
	}
	return res;
}
void initArrays(bool* inT, int* min, int* parents, int numOfVertices)
{

	for (int i = 1; i <= numOfVertices ; i++)
	{
		parents[i] = 0;
		min[i] = INT32_MAX;
		inT[i] = false;
	}

	min[1] = 0;
	parents[1] = 0;
}