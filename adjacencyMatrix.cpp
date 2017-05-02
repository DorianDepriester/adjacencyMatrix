#include "adjacencyMatrix.h"
#include <vector>
#include <iostream>
using namespace std;


adjacencyMatrix::adjacencyMatrix()
{
/**
 * Constructor
 */
	max_id_=0;
}

adjacencyMatrix::adjacencyMatrix(int n)
{
/**
 * Constructor
 * \param[in] n Original size of the matrix.
 */
	resize(n);
	max_id_=0;
}

void adjacencyMatrix::resize(int n_new){
/**
 * Enlarges the adjacency matrix.
 * \param[in] New size of the matrix
 */
	int n_old=mat_.size();
	if(n_new>n_old){
		for(int i=n_old;i<n_new;i++){
			vector<int> bottom(i,0);
			mat_.push_back(bottom);
		}
	}
}


bool adjacencyMatrix::Get(int id1, int id2){
/**
 * Checks if two nodes are connected. Returns true if yes, false otherwise.
 * \param[in]   id1 ID of the first node
 * \param[in]   id2 ID of the second node
 */
	int id;
	return Get(id1,id2,id);
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
	int n=size();
	if( (id1_s>n-1) || (id2_s<0) || (id1==id2) ){
		ide=0;
	} else {
		int val=mat_.at(id1_s).at(id2_s);
		if(id1>=id2){
			ide=val;
		}else{
			ide=-val;
		}
	}
	if (ide==0){
		return false;
	} else {
		return true;
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
	if ( (id1<0) || (id2<0) || (id1==id2) ){// Any negative input index, or trying to add self loop (forbidden in skew-matrices)
		max_id_++;
		ide=max_id_;
	} else {								// Both positive
		if( !( Get(id1,id2,ide) ) ){		// If the entry already exists, it just gets the edge ID
			max_id_++;
			if(id1>=id2){
				resize(id1+1);
				mat_.at(id1).at(id2)=max_id_;
			} else {
				resize(id2+1);
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

void adjacencyMatrix::print(){
/**
 * Prints the adjacency matrix
 */
    int n=size();
	int id;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Get(i,j,id);
			cout<<id<<"\t";
		}
		cout<<endl;
	}
}

adjacencyMatrix::~adjacencyMatrix()
{
/**
 * Destructor
 */
}
