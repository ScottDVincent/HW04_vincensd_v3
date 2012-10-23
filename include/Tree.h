/* 
 * @file Tree.h
 *  
 * @author Scott Vincent
 * @date 10-20-2012
 * CSE 274 - Fall 2012
 * My solution for HW04.
 *
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, mashup and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */


#include "Starbucks.h"



class Node{
public:		

//constructors
	Node();
	Node(Entry e);

			
	// node pointers in the tree
	Node* left_;
	Node* right_;
	
	// a Entry object to hold data	
	Entry* data;		


   };   // end member declarations


	
	/**
	* void contains
	* @param Node* delNode: Pointer to addy of the node to be deleted
	*/
	bool contains(Entry*);	

	/**
	* void search
	* @param string: Key value
	* @param Node* r: Pointer to addy of the node 
	*/
	Entry* search(string key, Node* r);

	/**
	* void insert
	* @param Entry: Entry object we are adding to the tree
	* @param Node* r: Pointer to addy of the node 
	*/
	Node* insert (Entry e, Node* r);

////////////////////// Stuff from previous project //////////////////////////////////////////////



	/**
	* void diplayList
	* @param node* inNode 
	* calls the drawRect function 
	*/
	void displayNode (Node* inNode);
	


	/**
	* int nodeCount
	* return an int with the number of nodes, including the sentinel 
	*/
	int nodeCount ();


	/**
	* bool isEmpty();
	* returns true if at end of list
	*/
	bool atEnd();


	/**
	* bool isEmpty();
	* returns true if list is empty. 
	* really shouldn't need this as I'm planning to go with a never-empty list
	*/
	bool isEmpty();