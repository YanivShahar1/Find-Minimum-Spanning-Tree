#pragma once
#include"Kruskal.h"


int kruskal(UnDirectedGraph& g, UnDirectedGraph& mst)
{ 
    int weightsum = 0;
	int numOfVertices = g.getNumOfVertices();
  
 
    mst.makeEmptyGraph(numOfVertices);
    if (g.is_sorted() == false)
    {
        g.qsort(0, g.getNumOfEdges() - 1);
    }
    cout << endl;
    DisjointSet UF(numOfVertices);

    for (int i = 1; i <= numOfVertices; i++)
    {
        UF.MakeSet(i);
    }
    Edge* edgeArr = g.getEdgesArr();
   
    for (int e = 0; e < g.getNumOfEdges(); e++)
    {
        int vv, uu;
        
        vv = edgeArr[e].v;
        uu = edgeArr[e].u;
      
        if (UF.Find(uu) != UF.Find(vv)) // different groups
        {
            mst.addEdge(uu,vv, edgeArr[e].c);
            UF.Union(UF.Find(vv), UF.Find(uu));
            weightsum += edgeArr[e].c;
        }
    }
    
    return weightsum;

}
