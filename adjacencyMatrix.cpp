#include "adjacencyMatrix.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


bool findInVect(vector<int> vect, int value, int& idx){
    std::vector<int>::iterator it;
    it = find (vect.begin(), vect.end(), value);
    if (it == vect.end()){
        return false;
    }else{
        idx=it-vect.begin();
        return true;
    }
}

int sub2ind(int i, int j){
    int ind;
    if(i<j){
        ind=j*(j-3)/2+i+1;
    }else{
        ind=i*(i-3)/2+j+1;
    }
    return ind;
}

void ind2sub(int& i, int& j, int ind){
    j=floor(1.5+sqrt(8.0*ind-7.0)/2);
    i=ind-(j*(j-3)/2+1);
}


adjacencyMatrix::adjacencyMatrix()
{
/**
 * Constructor
 */
	max_id_=0;
}



bool adjacencyMatrix::get(int id1, int id2){
/**
 * Checks if two nodes are connected. Returns true if yes, false otherwise.
 * \param[in]   id1 ID of the first node
 * \param[in]   id2 ID of the second node
 */
	int ide;
	return get(id1,id2,ide);
}

bool adjacencyMatrix::get(int id1, int id2, int& ide){
/**
 * Gets the id of the edge connecting two nodes in the graph. Returns true if the edge exists, false otherwise.
 * \param[in]   id1 ID of the first node
 * \param[in]   id2 ID of the second node
 * \param[out]  ide edge ID, if it exists in the adjacency matrix (0 otherwise)
 */
	int id1_s=min(id1,id2);
	int id2_s=max(id1,id2);
	if( (id1_s<0) || (id1==id2) ){
		ide=0;
	} else {
        int i;
        int ind=sub2ind(id1_s,id2_s);
        if(findInVect(inds_,ind,i)){
            if(id1<id2){
                ide=edgeIDs_.at(i);
            }else{
                ide=-edgeIDs_.at(i);
            }
        } else {
            ide=0;
        }
	}
	if(ide==0){
        return false;
	}else{
        return true;
	}
}

int adjacencyMatrix::add(int id1,int id2){
/**
 * Add new entry to the adjacency matrix and returns the edge ID. If the entry already exists, it returns the corresponding ID; otherwise, it increments the max ID and uses it.
 * If any of the imput argument is negative, it increments the max ID but returns 0.
 * \param[in] id1 ID of the first node
 * \param[in] id2 ID of the second node
 */
	int ide;
	int id1_s=min(id1,id2);
	int id2_s=max(id1,id2);
	if ( (id1_s<0) || (id1==id2) ){ // Any negative input index, or trying to add self loop (forbidden in skew-matrices)
		max_id_++;
		ide=max_id_;
	} else {                        // Both positive and different to each other
		if( !( get(id1,id2,ide) ) ){    // If the entry already exists, just get the edge ID; new edge otherwise
			max_id_++;
            inds_.push_back(sub2ind(id1_s,id2_s));
			if(id1<id2){
                edgeIDs_.push_back(max_id_);
			} else {
                edgeIDs_.push_back(-max_id_);
			}
			ide=max_id_;
		}
	}
	return ide;
}

void adjacencyMatrix::del(int id1,int id2){
/**
 * Deletes an entry (edge) from the adjacency matrix.
 * \param[in] id1 ID of the first node
 * \param[in] id2 ID of the second node
 */
	int ind=sub2ind(id1,id2);
	inds_.erase (inds_.begin()+ind-1);
	edgeIDs_.erase (edgeIDs_.begin()+ind-1);
}


int adjacencyMatrix::size(){
/**
 * Gets the size of the adjacency matrix.
 */
    if(inds_.size()==0){
        return 0;
    }else{
        int maxInd = *max_element(inds_.begin(), inds_.end());
        int i,j;
        ind2sub(i,j,maxInd);
        return j;
    }
}

void adjacencyMatrix::print(){
/**
 * Prints the adjacency matrix
 */
    int n=size();
	int ide;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			get(i+1,j+1,ide);
			cout<<ide<<"\t";
		}
		cout<<endl;
	}
//    for(int k=0;k<edgeIDs_.size();k++){
//        int i,j;
//        ind2sub(i,j,inds_.at(k));
//        int ind=sub2ind(i,j);
//        cout<<i<<"\t"<<j<<"\t"<<ind<<"\t"<<inds_.at(k)<<"\t"<<edgeIDs_.at(k)<<endl;
//    }
}

adjacencyMatrix::~adjacencyMatrix()
{
/**
 * Destructor
 */
}
