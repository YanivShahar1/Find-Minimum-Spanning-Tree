#pragma once

typedef struct Vertex
{
	int parent;
	int size;
};

class DisjointSet
{
private:
	Vertex* Varr;

public:
	DisjointSet(int);
	~DisjointSet();
	void MakeSet(int);
	int Find(int);
	void Union (int, int);
	int GetSize(int);
};