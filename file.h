#pragma once
#include"UnDirectedGraph.h"
#include<fstream>

void read_graph_from_file(UnDirectedGraph& g, char* file_name, Edge& edge_to_remove, ofstream& outputFile);

void read_graph_size(int* V, int* E, ifstream & readfile, ofstream& outputFile);

bool isWhole(double num);
void read_edges(UnDirectedGraph& g, int numOfEdges, int numOfVertices, ifstream& readFile, Edge& edge_to_remove, ofstream& outputFile);

bool valid_vertex(double v, double n);