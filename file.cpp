#include"file.h"
#include <string>
void read_graph_from_file(UnDirectedGraph& g, char* file_name, Edge& edge_to_remove, ofstream& outputFile)
{
	ifstream readFile;
	readFile.open(file_name);
	if (!readFile)
	{
		cout << "Error reading the file!!" << endl;
		outputFile << "Error reading the file!!" << endl;
		outputFile.close();
		readFile.close();
		exit(1);
	}
	

	int numOfVertices, numOfEdges;

	read_graph_size(&numOfVertices, &numOfEdges, readFile, outputFile);
	g.makeEmptyGraph(numOfVertices);

	read_edges(g, numOfEdges, numOfVertices, readFile, edge_to_remove, outputFile);

	readFile.close();

}

void read_edges(UnDirectedGraph& g, int numOfEdges, int numOfVertices, ifstream& readFile, Edge& edge_to_remove, ofstream& outputFile)
{
	int i = 0;
	int count = 0;
	double u;

	if (numOfEdges == 0)
		return;

	string line;
	double q1, q2, c;
	bool v1 = true, v2 = false, weight = false;

	while (readFile >> u)
	{
		count++;
		if (v1)
		{

			q1 = u;
			v1 = false;
			v2 = true;
		}
		else if (v2)
		{
			q2 = u;
			v2 = false;
			weight = true;
		}
		else if (weight)
		{
			if (!valid_vertex(q1, numOfVertices) || !valid_vertex(q2, numOfVertices) || !isWhole(u))
			{
				cout << "Invalid input value ! " << endl;
				outputFile << "Invalid input value ! " << endl;
				readFile.close();
				outputFile.close();
				exit(1);
			}
			c = u;
			weight = false;
			v1 = true;
			g.addEdge(q1, q2, c);
		}
		if (count == numOfEdges * 3 + 1)//Each edge contain 3 inputs from file + 1 for first delete vertex
		{
			edge_to_remove.u = u;

		}
		if (count == numOfEdges * 3 + 2)//Each edge contain 3 inputs from file + 2 second delete vertex
		{
			edge_to_remove.v = u;
		}

	}
	if (count != numOfEdges * 3 + 2)//The number of inputs need to be 3(for edge) + 2 for delete edge
	{
		cout << "Invalid input !" << endl;
		outputFile << "Invalid input !" << endl;
		readFile.close();
		outputFile.close();
		exit(1);
	}
}
void read_graph_size(int* V, int* E, ifstream & readfile, ofstream& outputFile)
{
	int v, e;
	readfile >> v >> e;
	if (!isWhole(v) || !isWhole(e) || v < 0 || e < 0 )
	{
		cout << "Invalid value for the graph size ! " << endl;
		outputFile<< "Invalid value for the graph size ! " << endl;
		readfile.close();
		outputFile.close();
		exit(1);
	}
	*V = v;
	*E = e;

}

bool isWhole(double num)
{
	return num == static_cast<int>(num);
}

bool valid_vertex(double v, double n)
{
	return isWhole(v) && v <= n && v>=1;
}