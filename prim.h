#pragma once
#include"UnDirectedGraph.h"

void initArrays(bool* inT, int* min,int* parents,int numOfVertices);

int findWeight(int u, int v, UnDirectedGraph& g);

int prim(UnDirectedGraph& g);