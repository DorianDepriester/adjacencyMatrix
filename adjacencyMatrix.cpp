#include "adjacencyMatrix.h"
#include <vector>
using namespace std;


adjacencyMatrix::adjacencyMatrix()
{
}

bool adjacencyMatrix::Get(int id1, int id2, int& rval){
	int n=m_mat.size();
	if( (id1<0) || (id1>n-1) || (id2<0) || (id2>n-1) ){
        return false;
	}else{
        if (m_mat.at(id1).at(id2).empty()){
            return false;
        } else {
            rval=m_mat.at(id1).at(id2).at(0);
            return true;
        }
	}
}

void resize(vector<vector<vector<int> > >& mat,int nNew){
    int nOld=mat.size();
    vector<int> val;
    int i;
    for(i=0;i<nOld;i++){
        mat.at(i).resize(nNew,val);
    }
    vector<vector<int> > bottom(nNew,val);
    for(i=0;i<nNew-nOld;i++){
        mat.push_back(bottom);
    }
}

void adjacencyMatrix::Set(int id1,int id2, int val){
	if( (id1>=0) & (id2>=0) ){
		int n=m_mat.size();
		int idm=max(id1,id2);
		if(idm>n-1){
            resize(m_mat,idm+1);
		}
		m_mat.at(id1).at(id2).push_back(val);
        m_mat.at(id2).at(id1).push_back(-val);
	}
}


adjacencyMatrix::~adjacencyMatrix()
{
    //dtor
}
