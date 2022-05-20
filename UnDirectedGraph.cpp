#include "UnDirectedGraph.h"

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void UnDirectedGraph::makeEmptyGraph(int n)
{
	edgeArr = new Edge[(n * (n - 1)) / 2]();
	if (n < 0)
	{
		cout << "invalid input";
		exit(1);
	}

	arr = new List[n + 1]();
	for (int j = 0; j < n + 1; j++)
	{
		arr[j].makeEmptyList();
	}
	size = n + 1 ;
	numOfVertices = n;
}
bool UnDirectedGraph::isAdjacent(int u, int v)const
{
	return(arr[u].findInList(v) != nullptr);
}
const List * UnDirectedGraph::getAdjList(int u) const
{
	return &arr[u];
}
void UnDirectedGraph::addEdge(int u, int v, int c) 
{
	Node* p1, * p2;
	p1 = arr[u].insertToList(v,c);
	p2 = arr[v].insertToList(u,c);

	edgeArr[numOfEdges].u = u;
	edgeArr[numOfEdges].v = v;
	edgeArr[numOfEdges].c = c;
	
	numOfEdges += 1;
	
}
void UnDirectedGraph::removeEdge(int u, int v)
{
	if (u <= 0 || v <= 0 || u > numOfVertices || v > numOfVertices)
	{
		cout << "invalid vertex to remove ! ";
		exit(1);
	}
	if (arr)
	{
		arr[u].deleteFromList(v);
		arr[v].deleteFromList(u);

		// remove edge from edgearr : 
		for (int e = 0; e < numOfEdges; e++)
		{
			if ((edgeArr[e].u == u && edgeArr[e].v == v) ||
				(edgeArr[e].u == v && edgeArr[e].v == u))
			{
				remove_edge_from_arr(e);
			}
		}
		numOfEdges--;
	}
}
void UnDirectedGraph::remove_edge_from_arr(int edge_index)
{
	for (int e = edge_index; e < numOfEdges - 1; e++)
	{
		edgeArr[e].u = edgeArr[e + 1].u;
		edgeArr[e].v = edgeArr[e + 1].v;
		edgeArr[e].c = edgeArr[e + 1].c;
	}

}
void UnDirectedGraph::visit(int v)
{
	color[v] = GRAY;
	const List* adj = getAdjList(v);
	Node* curr = adj->getHead();

	while (curr != nullptr)
	{
		if (color[curr->vertex] == WHITE)
		{
			visit(curr->vertex);
		}
		curr = curr->next;
	}
	color[v] = BLACK;
}

bool UnDirectedGraph::is_connected()
{
	color = new int[numOfVertices + 1]();
	for (int v = 1; v <= numOfVertices; v++)
	{
		color[v] = WHITE;
	}

	if (numOfVertices > 1)
	{
		visit(1);

		//check if all the verticies are black
		for (int v = 1; v <= numOfVertices; v++)
		{
			if (color[v] != BLACK)
				return false;
		}
		return true;
	}
	else
		return true;
	
}

void UnDirectedGraph::qsort(int start, int end)
{
	// base case
	if (start >= end)
	{
		edges_is_sorted = true;
		return;
	}
		

	// partitioning the array
	int p = partition(start, end);

	// Sorting the left part
	qsort(start, p - 1);

	// Sorting the right part
	qsort(p + 1, end);
}

int UnDirectedGraph::partition(int start, int end)
{
	int pivot = edgeArr[start].c;

	int count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (edgeArr[i].c <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(edgeArr[pivotIndex], edgeArr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (edgeArr[i].c <= pivot) {
			i++;
		}

		while (edgeArr[j].c > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(edgeArr[i++], edgeArr[j--]);
		}
	}

	return pivotIndex;
}