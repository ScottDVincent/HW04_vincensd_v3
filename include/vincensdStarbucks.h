/*****
 * File: vincensdStarbucks.h	
 * Author   : vincensd
 * Date     : 2012-10-10
 * Sources  : 
 * Purpose  :  Your starbucks data structure should be  
 a sub-class of this class, but you should not implement this class. 
 Instead, you should   create a <uniqueid>Starbucks class, in the files <uniqueid>Starbucks.h and  
 <uniqueid>Starbucks.cpp
 */
 
#pragma once
#include "Starbucks.h"
// std includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;
std::stringstream;


 
 class vincensdStarbucks : public Starbucks{
public:
	
	// Members vars
	Entry* entryArrBld; 
	int arraySize;
	Entry* closestBucks;

	/**
	Constructor Method
	*/
	// no arguemnt constructor
	vincensdStarbucks();
	//Entry();
	
	// stuff constructor 
	//vincensdStarbucks::vincensdStarbucks( /** what do I want */);

	/** 
	Member vars
	*/
	//vector<Entry> entryVec;
	

	/*
	 * add all entries in the array to your data structure
	 *
	 * The "c" parameter is a pointer to an array of all the entries to be added, and n is the length of  the array.
	 *
	 * Note: If you detect that two items have the same coordinates, then do not add the new item that has the same coordinates as another item. 
	 This is guaranteed to happen, by the way, because some Starbucks locations are listed in the database twice. 
	 We will define two locations to be the "same location" if both |x1 - x2| <= 0.00001 and |y1 - y2| < 0.00001
	 */
	void build(Entry* c, int n) ;
	
	/*
	 * Return a pointer to the entry that is closest to the given coordinates. Your
	 *  answer may be approximate, but then you will lose points on the "Accuracy" quality measure
	 */
	Entry* getNearest(double x, double y);
	
	
	/**
	Destructor Method
	*/


};