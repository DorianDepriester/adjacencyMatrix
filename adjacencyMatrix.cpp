#include "adjacencyMatrix.h"
#include <vector>
using namespace std;


adjacencyMatrix::adjacencyMatrix()
{
/**
 * Constructor
 */
    max_id_=0;
}

bool adjacencyMatrix::Get(int id1, int id2){
/**
 * Checks if two nodes are connected. Returns true if yes, false otherwise.
 * \param[in]   id1 ID of the first node
 * \param[in]   id2 ID of the second node
 */
    	int id1_s=max(id1,id2);
	int id2_s=min(id1,id2);
	int n=mat_.size();
	if( (id1_s>n-1) || (id2_s<0) ){
        	return false;
	} else {
        	int val=mat_.at(id1_s).at(id2_s);
        	if (val==0){
            		return false;
        	} else {
            		return true;
        	}
	}
}

bool adjacencyMatrix::Get(int id1, int id2, int& ide){
/**
 * Gets the id of the edge connecting two nodes in the graph. Returns true if the edge exists, false otherwise.
 * \param[in]   id1 ID of the first node
 * \param[in]   id2 ID of the second node
 * \param[out]  ide edge ID, if it exists in the adjacency matrix
 */
	int id1_s=max(id1,id2);
	int id2_s=min(id1,id2);
	int n=mat_.size();
	if( (id1_s>n-1) || (id2_s<0) ){
        	return false;
	} else {
		int val=mat_.at(id1_s).at(id2_s);
		if (val==0){
			return false;
        	} else {
			if(id1>=id2){
				ide=val;
			}else{
				ide=-val;
			}
			return true;
		}
	}
}

void resize(vector<vector<int> >& mat,int nNew){
/**
 * Enlarges the adjacency matrix.
 * \param[in,out] mat matrix to be enlarged
 * \param[in] New size of the matrix
 */
    int nOld=mat.size();
    int i;
    for(i=nOld;i<nNew;i++){
        vector<int> bottom(i,0);
        mat.push_back(bottom);
    }
}

int adjacencyMatrix::Set(int id1,int id2){
/**
 * Add new entry to the adjacency matrix and returns the edge ID. If the entry already exists, it returns the corresponding ID; otherwise, it increments the max ID and uses it.
 * If any of the imput argument is negative, it increments the max ID but returns 0.
 * \param[in] id1 ID of the first node
 * \param[in] id2 ID of the second node
 */
	int ide;
	if ( (id1<0) || (id2<0) ){ // Any negative input index
		max_id_++;
		ide=max_id_;
	} else {                    // Both positive
		if( !( Get(id1,id2,ide) ) ){    // If the entry already exists, it just gets the edge ID
			max_id_++;
			if(id1>=id2){
				resize(mat_,id1+1);
				mat_.at(id1).at(id2)=max_id_;
			} else {
				resize(mat_,id2+1);
				mat_.at(id2).at(id1)=-max_id_;
			}
			ide=max_id_;
		}
	}
	return ide;
}


int adjacencyMatrix::size(){
/**
 * Gets the size of the adjacency matrix.
 */
    return mat_.size();
}

adjacencyMatrix::~adjacencyMatrix()
{
/**
 * Destructor
 */
}
