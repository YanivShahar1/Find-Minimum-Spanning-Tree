#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include"UnDirectedGraph.h"
#include"Kruskal.h"
#include"prim.h"
#include"file.h"

using namespace std;

void main(int argc, char** argv)
{
	if (argc <= 2)
	{
		cout << "invalid amount of argc..";
		exit(1);
	}
	UnDirectedGraph g;
	Edge edge_to_remove;
	ofstream outputFile;
	outputFile.open(argv[2]);
	
	read_graph_from_file(g, argv[1], edge_to_remove, outputFile);
	int weight = 0,prim_weight;
	UnDirectedGraph MST;
	if (!g.is_connected())
	{
		cout << "NO MST, The Graph Is Not Connected" << endl;
		outputFile << "NO MST, The Graph Is Not Connected" << endl;
		outputFile.close();
		exit(1);
	}
	
	weight = kruskal(g, MST);
	
	if (MST.is_connected())
	{
		cout << "Kruskal: " << weight << endl;
		outputFile << "Kruskal: " << weight << endl;
	}
	else
	{
		cout << "No MST" << endl;
		outputFile << "No MST" << endl;
	}
	prim_weight = prim(g);
	cout << "Prim: " << prim_weight<<endl ;
	outputFile << "Prim: " << prim_weight << endl;
	g.removeEdge(edge_to_remove.v, edge_to_remove.u);
	if (g.is_connected())
	{
		if (MST.isAdjacent(edge_to_remove.v, edge_to_remove.u))
		{
			weight = kruskal(g, MST);
			if (MST.is_connected())
			{
				cout << "Kruskal2: " << weight << endl;
				outputFile << "Kruskal2: " << weight << endl;
			}
			else
			{
				cout << "Kruskal2: No MST" << endl;
				outputFile << "Kruskal2: No MST" << endl;
			}
		}
		else //not Adjacent - The weight of the MST doen't changed.
		{
			cout << "Kruskal2: " << weight << endl;
			outputFile << "Kruskal2: " << weight << endl;
		}
	}
	else
	{
		cout << "Kruskal2: No MST" << endl;
		outputFile << "Kruskal2: No MST" << endl;
	}
	outputFile.close();
}