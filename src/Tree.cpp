/*
 * @file Tree.cpp
 *
 * @author Scott Vincent
 * @date 10/20/2012
 * CSE 274 - Fall 2012
 * My solution for HW04.
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */ 

#include "Tree.h"

#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;		// standard library


	/** 
	 * Constructs Node object which points to itself and has a data_ member
	 */  

	Node::Node () {}
	
	Node::Node(){
		left_ = right_ = NULL;		// create self-referential node; the assignments go in reverse order
		data = new Entry();		
		
	}


	// ?? have to do something to create the root node ?? -- I dont think so -- no Node* root;
	
	Key k; // k = (x & y, 2 doubles)

	/**
	* Entry* contains
	* @param Key k, 
	* @param Node* r
	*/
	Entry* contains(Key k, Node* r) {
		if (r ==NULL)  
			return NULL; 

		if ( r-> key == k) 
			return &(r -> data);

		if ( k < r -> key) {
				return contains (k, r -> left_ );
		} else {
				return contains (k, r -> right_ );
		}


	}	// end contains


	/**
	* void printInOrder
	* @param Node* r: Pointer to addy of the node 
	*/
	void printInOrder (Node* r) {
		if (root == NULL ) 
			return;

		printInOrder (r-> left_);
		cout << r -> data << flush;
		printInOrder (r -> right_);
	
	} // end pIO



	/**
	* void search
	* @param string: Key value
	* @param Node* r: Pointer to addy of the node 
	*/
	Entry* search(Key k, Node* r){ 

		if (r == NULL)
			return NULL;
		if (Key == r -> Key)
			return r -> Entry;	// this would never happen that q would be the location

		Entry* best_left = search (Key k , r -> left_, !isXLevel);
		Entry* best_right = search (Key k, r -> right_; !isXLevel;
		Entry* current_entry = r -> data;



	} //end search



	/**
	* void insert
	* @param Entry: Entry object we are adding to the tree
	* @param Node* r: Pointer to addy of the node 
	*/
	Node* insert (Entry e, Node* r){ 

		if ( r == NULL)
			return new Node*(e);
		if (r -> key == e -> key) 
			return r;

		// for x Level
		if (e -> key < r -> key){
			r -> left_ = insert (e, r-> left_, !isXLevel);     //
		} else {
			r -> right_ = insert (e, r -> right_, !isXLevel);	//
		} 

		//for Y Level
		if (e -> key > r -> key){
			r -> left_ = insert (e, r-> left_, !isYLevel);     //
		} else {
			r -> right_ = insert (e, r -> right_, !isYLevel);	//
		} 

		return r;
	}



	/**
	* Node* next
	* @param node* r 
	* @param key
	*/
	Node* next(Node* r, key){
		if (r== NULL) { 
		return NULL;
		
		} else if  (key > r-> key) {
		 return next (key, r -> right_);
		 
		} else {
			Node* temp = next (key, r -> left_); 
		 
		 if (temp == NULL){
			  return r;
		  } else {
			  return temp;
	  }
	}

	/**
	* Entry* nearest
	* @param k
	*/
	Entry* nearest(key) {
		
		}


	/**
	* void remove
	* @param k
	* @param k
	*/
	Node* remove (Node* r, key) {

		if (r == NULL) { 
			return r;
		 } else if {
		  ( r -> key == key) {

				if (r -> left_ == NULL) {
				 Node* temp = r -> right_;
				 delete r;
				 return temp;
 
				 } else if {
					 ( r -> right_ == NULL){
					 Node* temp = r -> left_;
					 delete r;
					 return temp;

				 } else {									// has two children
					 Node* temp = min (r-> right_);
					 swap (temp,r);
					 r -> right_ = remove (key, r->right_); // lazy update
					 return r;	
		
			 } else {
		
					if (k < r -> key) {
						r -> left_ = remove (key, r-> left_);
						return r;
			
					} else {
						r -> left_ = remove (key, r-> left_);
						return r;
						}
				}
		 }



	/**
	* Node* min
	* 
	*/
	Node* min(Node* r) {
		if (r == NULL || r -> left_ == NULL)  {
			return r;
		} else {
			return min ( r-> left_);
		}
	} // end min


	/** 
	Node* max
	* code from remove
	*
	*/