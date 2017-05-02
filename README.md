# adjacencyMatrix
Simple and lightweight oriented adjancency matrix implementation for C++. 

## How to use
### Install
Just put the `.h` and `.cpp` files in the working directory, and add the following line in the file where you want to use the adjacency matrix:

    #include "adjacencyMatrix.h"

## Examples
### Create a new instance of adjacency matrix

    adjacencyMatrix adj_mat;
    
Note that the size of the matrix is not mandatory here, since it will be dynamically computed (see below).    

### Add a new entry in the adjacency matrix

    int id1=1,id2=2;
    adj_mat.Set(id1,id2);
    
A unique ID is automatically associated to the new edge (starting from 1, incrementing by 1 each time a new entry is added). If necessary, the size of the matrix is dynamically increased.
    
### Check if an edge exists between node id1 and node id2

    adj_mat.Get(id1,id2);
    
### Check if an edge exists between node id1 and node id2 and get the corresponding edge ID

    int ide;
    adj_mat.Get(id1,id2,ide);
    
## How it works
Since the oriented adjacency matrices are skew-symmetric, data are stored as lower triangular matrices, in a sake of memory.
    
## Notes
### Self loop
Dispite the skew-symmetry, this class allows to define self loop. In this special case, no symmetry is introduced. Thus, the diagonal is always positive.

### Negative node indices
If any input argument of `Set` is negative, no entry is added to the matrix. Still, the maximum edge ID is incremented.

### Purpose
The class was designed for the [voroGmsh](https://github.com/DorianDepriester/voroGmsh "voroGmsh on GitHub") class.

