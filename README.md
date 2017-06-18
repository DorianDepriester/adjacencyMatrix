# adjacencyMatrix
Simple and lightweight C++ implementation for oriented adjancency matrices.

## What's that?
> In graph theory and computer science, an adjacency matrix is a square matrix used to represent a finite graph. The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph.
> -- [Wikipedia](https://en.wikipedia.org/wiki/Adjacency_matrix)

The original graph consists in nodes (aka vertices), connected to others by a set of edges. In directed graphs, the so-called oriented adjacency matrix indicates wheter each edge is walked by forward or backward; hence, it is skew-symmetric.

### Example
Here is an example graph:

![Example graph](https://i1.wp.com/blog.dorian-depriester.fr/wp-content/uploads/2017/06/Graphe.png?resize=150%2C150 "Example graph")

Its consists in vertices (rounded nodes) and oriented edges (arrows). The corresponding adjacency matrix is:

![Adjacency matrix](https://latex.codecogs.com/png.latex?%5Cinline%20A%3D%5Cbegin%7Bpmatrix%7D%200%20%26%201%20%260%20%26%200%5C%5C%20-1%20%26%200%20%26%202%20%26%20-4%5C%5C%200%20%26%20-2%20%26%200%20%26%20-3%5C%5C%200%20%26%204%20%26%203%20%26%200%20%5Cend%7Bpmatrix%7D "Adjacency matrix")


## How to use
### Install
Just put the `.h` and `.cpp` files in the working directory, and add the following line in the file where you want to use the adjacency matrix:

    #include "adjacencyMatrix.h"

## Examples
### Create a new instance of adjacency matrix

    adjacencyMatrix adj_mat;
    
Note that the size of the matrix is not mandatory here, since it will be dynamically computed (see below). If the size of the matrix is already known, it can passed to the constructor:

    adjacencyMatrix adj_mat(7);

### Add a new entry in the adjacency matrix

    int id1=1,id2=2;
    int ide=adj_mat.add(id1,id2);
    
A unique ID is automatically associated to the new edge (starting from 1, incrementing by 1 each time a new entry is added). If necessary, the size of the matrix is dynamically increased.
    
### Check if an edge exists between node id1 and node id2

    adj_mat.get(id1,id2);
    
### Check if an edge exists between node id1 and node id2 and get the corresponding edge ID

    int ide;
    adj_mat.get(id1,id2,ide);
    
### Display the adjacency matrix

    adj_mat.print();

## How it works
Since the oriented adjacency matrices are skew-symmetric, data are stored as lower triangular matrices, in a sake of memory.
    
## Notes
### Self loop
Because of the skew-symmetry, self loops are forbidden in oriented adjacency matrices. Hence, the diagonal is always zero.

### Negative node indices
If any input argument of `Set` is negative, no entry is added to the matrix. Still, the maximum edge ID is incremented. The same behaviour applies for equal indices (see above).

### Purpose
The class was designed for the [voroGmsh](https://github.com/DorianDepriester/voroGmsh "voroGmsh on GitHub") class.

