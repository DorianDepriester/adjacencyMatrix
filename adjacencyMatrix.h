#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <vector>
using namespace std;


class adjacencyMatrix
{
    public:
        adjacencyMatrix();
        /**
        * Constructor
        */
        virtual ~adjacencyMatrix();
        /**
        * Destructor
        */
        bool get(int id1, int id2);
        /**
        * Returns true if the entry exists in the adjacency matrix.
        */
        bool get(int id1, int id2, int&);
        /**
        * Returns true if the entry exists in the adjacency matrix and gives the ID of the existing entry.
        */
        int add(int id1, int id2);
        /**
        * Add a new entry to the adjacency matrix and returns its ID.
        */
        void del(int id1, int id2);
        /**
        * Deletes an entry in the adjacency matrix.
        */
        int size();
        /**
        * Returns the size of the adjacency matrix (number of columns).
        */
        void print();
        /**
        * Prints out the content of the adjacency matrix.
        */
    private:
        int max_id_;
        vector<int> inds_;
        vector<int> edgeIDs_;
};

#endif // ADJACENCYMATRIX_H
