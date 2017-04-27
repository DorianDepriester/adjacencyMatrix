#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <vector>
using namespace std;


class adjacencyMatrix
{
    public:
        adjacencyMatrix();
        virtual ~adjacencyMatrix();
        bool Get(int id1, int id2, int&);
        void Set(int id1, int id2,int val);
    protected:
    private:
        vector<vector<vector<int> > > m_mat;
};

#endif // ADJACENCYMATRIX_H
