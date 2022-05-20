#pragma once

#include "List.h"
#include <chrono> 
#include <iostream>
#include <fstream>
#include <iomanip>


typedef struct Edge
{
	int u, v, c; // c is the weight
}Edge;

class UnDirectedGraph
{
private:
	int numOfVertices= 0, numOfEdges = 0;
	List* arr = nullptr; // array of lists - Adjacency List
	Edge* edgeArr = nullptr; // array of edges -> for kruskal algorithm
	int size;

	int * color = nullptr; 

private:
	bool edges_is_sorted = false;
	int partition(int start, int end);
	void remove_edge_from_arr(int edge_index);
	
public:
	UnDirectedGraph() :arr(nullptr), size(0){}

	~UnDirectedGraph()
	{
		for (int i = 0; i < size; i++)
			arr[i].makeEmptyList();

		size = 0;
	}
	void qsort(int start, int end);

	Edge* getEdgesArr() { return edgeArr; }
	void makeEmptyGraph(int);    // Makes empty graph input: graph size
	bool isAdjacent(int, int) const;	 // Checks if two verticies are adjcent, input two vertices	
	const List* getAdjList(int) const; // retrives list of neighbors, input : vertex
	void addEdge(int u, int v , int c) ;      // add an edge to a graph, input two verticies
	void removeEdge(int, int);   // remove an edge from the graph, input two verticies
	
	int isEmpty() const { return size == 0 ? 1 : 0; } // checks if there are no verticites in the graph
	int getSize()const { return size - 1; }          // retrives the size of the graph

	int getNumOfEdges()const { return numOfEdges; }
	int getNumOfVertices()const { return numOfVertices; }

	void setNumOfVertices(int v) { numOfVertices = v; }

	bool is_connected();
	bool is_sorted() const{ return edges_is_sorted; }
	void visit(int v);


	void printGraph()const
	{
		cout << "Graph: " << endl;
		for (int i = 1; i <= numOfVertices; i++)
		{
			cout << "The list of vertex " << i << ":" << endl;
			arr[i].printList(i);
			cout << endl;
		}
	}

	void print_edges()
	{
		for (int e = 0 ;e < numOfEdges; e++)
		{
			cout << edgeArr[e].u<<' ' ;
			cout << edgeArr[e].v <<' ';
			cout << edgeArr[e].c << endl;
		}

	}

};