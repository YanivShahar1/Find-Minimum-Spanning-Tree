#pragma once
#include"DisjointSet.h"

#include<iostream>
using std::cout;
using std::endl;
DisjointSet::DisjointSet(int size)
{
	Varr = new Vertex[size +1]();
	for (int i = 0; i <= size; i++)
	{
		Varr[i].parent = -1;
		Varr[i].size = 0;
	}
}

void DisjointSet::MakeSet(int x)
{
	Varr[x].parent = x;
	Varr[x].size = 1;
}

int DisjointSet::Find(int x)
{
	if (Varr[x].parent == x)
		return x;

	return (Varr[x].parent = Find(Varr[x].parent));
}
DisjointSet::~DisjointSet()
{

	if (Varr) // if allocated
		delete[] Varr;
}
void DisjointSet::Union(int u, int v)
{
	if (GetSize(u) > GetSize(v))
	{
		Varr[v].parent = u;
		Varr[Find(u)].size += Varr[v].size;
	}
	else
	{
		Varr[u].parent = v;
		Varr[Find(v)].size += Varr[u].size;
	}
}
int DisjointSet::GetSize(int x)
{
	return Varr[Find(x)].size;
}

