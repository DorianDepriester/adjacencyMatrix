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
 * Resizes the matrix so that it contains n vertices.
 * \param[in] n_new New size of the matrix
 */
	int n_old=size();
	if(n_new>n_old){
		for(int i=n_old;i<n_new;i++){	// Enlarge the matrix
			vector<int> bottom(i,0);
			mat_.push_back(bottom);
		}
	} else if(n_new<n_old) {			// Shrink the matrix
		mat_.resize(n_new);
		for(int i=0;i<n_new;i++){
			mat_.at(i).resize(n_new-1);
		}
	}
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

int adjacencyMatrix::add(int id1,int id2){
/**
 * Add new entry to the adjacency matrix and returns the edge ID. If the entry already exists, it returns the corresponding ID; otherwise, it increments the max ID and uses it.
 * If any of the imput argument is negative, it increments the max ID but returns 0.
 * \param[in] id1 ID of the first node
 * \param[in] id2 ID of the second node
 */
	int ide;
	int n=size();
	int id1_s=max(id1,id2);
	int id2_s=min(id1,id2);
	if ( (id2_s<0) || (id1==id2) ){// Any negative input index, or trying to add self loop (forbidden in skew-matrices)
		max_id_++;
		ide=max_id_;
	} else {								// Both positive and different to each other
		if( !( get(id1,id2,ide) ) ){		// If the entry already exists, just get the edge ID; new edge otherwise
			max_id_++;
			if(id1_s+1>n){
				resize(id1_s+1);			// If the matrix is too small, enlarge it
			}
			if(id1>=id2){
				mat_.at(id1).at(id2)=max_id_;
			} else {
				mat_.at(id2).at(id1)=-max_id_;
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
	int n=size();
	int id1_s=max(id1,id2);
	int id2_s=min(id1,id2);
	if ( (id2_s>=0) && (id1_s<n-1) ){
		mat_.at(id1_s).at(id2_s)=0;
	}
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
			get(i,j,id);
			cout<<id<<"\t";
		}
		cout<<endl;
	}
}

int adjacencyMatrix::nEdges(){
/**
 * Returns the number of edges
 */
    return max_id_;
}

adjacencyMatrix::~adjacencyMatrix()
{
/**
 * Destructor
 */
}
