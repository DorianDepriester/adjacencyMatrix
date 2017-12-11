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
        adjacencyMatrix(int);
        /**
        * Constructor, giving the original size of the matrix.
        */
        virtual ~adjacencyMatrix();
        /**
        * Destructor
        */
		void resize(int);
		/**
		* Change the size of the adjacency matrix.
		**/
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
        int nEdges();
        /**
        * Returns the number of edges
        */
        void print();
        /**
        * Prints out the content of the adjacency matrix.
        */
    private:
        vector<vector<int> > mat_;
        int max_id_;
};

#endif // ADJACENCYMATRIX_H
