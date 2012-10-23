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

	//Node::Node () {}
	
	Node::Node(){
		left_ = right_ = NULL;		// create self-referential node; the assignments go in reverse order
		data = new Entry();		
		
	}

	// have to do something to create the root node
	Node* root;


///////////////////////////////////////////////////////////////////////////////

/**
* displayNode
*@param inNode 
*argument is a a single Node object, passed in from traverseList,  to be printed
*/
void displayNode (Node* inNode){		
	  
	// draw this single node being passed in
}

 

/**
* nodeCount
@param sentinel start counting from the sentinel
*return an int with the number of nodes, including the sentinel
*/ 

/**
int nodeCount (Node* sentinel){

		Node* cur = sentinel -> next_;
		int theCount = 1;				// includes the sentinel

		while(cur != sentinel) {
			theCount++;
			cur = cur->next_;
			}
		return theCount;

}
*/