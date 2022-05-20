# Find-Minimum-Spanning-Tree

The program find a minimum spanning tree from an undirected edge-weighted graph.
I have implemented Kruskal and Prim algorithms to find the MST.
The graph is implemented by Adjacancy List.

The program calculate MSt by kruskal algorithm, and then by Prim algorithm ,and print the output (weights of the MST) to the screen and also to the output file,
Then the program will remove the edge between the two vertices in the last row of the input file,
and will calculate again the weight of the minimum spanning tree of the new graph, using Kruskal algorithm.


# Notes ❗ :

The program builds the graph using an input file, the sructure of the input file:

        Number of vertices
        Number of edges (|E|)
        u, v , w  (Edge, represented by 3 numbers : u, v (the verticies) and then w (the weight of this edge) ).
        . . .
        . . .
        . . .
        . . .
        
        . . . (|E| rows for edges)
        
        u , v (The edge that should be removed from the graph)


The program will not work if there's a negative weighted cycle in the graph.
I have added some input files to test the program

Please notice that command line arguments are needed to run this program!
  In Visual studio:
    Properties-> command line agruments -> "input_file_name" "output_file_name".
    
Feel free to contact me for any question or problem.
