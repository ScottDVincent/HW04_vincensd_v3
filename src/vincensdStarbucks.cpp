/*****
 * File: vincensdStarbucks.cpp	
 * Author   : vincensd
 * Date     : 2012-10-10
 * Sources  : 
 * Purpose  :  Your starbucks data structure should be   
 a sub-class of this class, but you should not implement this class. 
 Instead, you should   create a <uniqueid>Starbucks class, in the files <uniqueid>Starbucks.h and 
 <uniqueid>Starbucks.cpp

 Some helpful ideas
 http://www.daniweb.com/software-development/cpp/threads/50051/how-to-read-data-from-csv-file-in-an-array-and-parse
 http://stackoverflow.com/questions/5265160/using-getline-to-extract-information-and-store-them-in-a-datatype-in-c?rq=1
 /http://stackoverflow.com/questions/12233596/reading-csv-data-from-a-file?rq=1
 */
 
#include "vincensdStarbucks.h"



	/** 
	*Default vincensdStarbucks constructor
	*/  
	vincensdStarbucks::vincensdStarbucks(){
	}

	/** 
	*vincensdStarbucks constructor
	do I really need a constructor with parameters?
	 */ 
	//vincensdStarbucks::vincensdStarbucks( /** what do I want in here?  */){}
	



	/*
	 * add all entries in the array to your data structure
	 *
	 * The "c" parameter is a pointer to an array of all the entries to be added, 
	 and n is the length of the array.
	 *
	 * Note: If you detect that two items have the same coordinates, 
	 then do not add the new item that has the same coordinates as another item. 
	 This is guaranteed to happen, by the way, because some Starbucks locations are listed in the database twice. We will define two locations to be the "same location" if both |x1 - x2| <= 0.00001 and |y1 - y2| < 0.00001
	 */
	void vincensdStarbucks::build(Entry* c, int n){
		
		//int addyCounter = c;
		//Entry *entryArrBld = new Entry [n];	// as in setup, we have to do a dynamic array definition to use 'n'
		entryArrBld  = new Entry [n];
		arraySize = n;

		for (int i = 0; i <= (arraySize-1); i++ ){ 
			entryArrBld[i] = *c;		// put in the dereferenced Entry object into array slot
			c = c + 1;					// add 48 bytes (size of Entry object) to the address of c to get the next entry
										// http://www.cs.fsu.edu/~myers/cgs4406/notes/pointers.html
		}

		cout << "output = " << &entryArrBld[0] << endl;
		cout << "output = " << &entryArrBld[7654] << endl;
	}
	
	/*
	 * Return a pointer to the entry that is closest to the given coordinates. Your
	 *  answer may be approximate, but then you will lose points on the "Accuracy" quality measure
/**	 */

	
	Entry* vincensdStarbucks::getNearest(double x, double y) {
		
		//Entry* e;
		double qX = x;
		double qY = y;
		double difX, finX ;
		double difY, finY;
		/**	
		*/
		// set distance of first point
		double distanceSmallest = 1.1;

		// loop thru points
		for (int i = 0; i <= arraySize; i++) {
				
			double starX = entryArrBld[i].x;
			double starY = entryArrBld[i].y;

			// find x
			difX = abs(qX - starX);
			finX = pow(difX, 2);
			// find y
			difY = abs(qY - starY);
			finY = pow(difY, 2);


		double distanceTwo = sqrt( finX + finY );
			if  (distanceTwo < distanceSmallest){
					distanceSmallest = distanceTwo;
					// ? how to equate the Entry w/ the smallest (x,y) coords
					closestBucks = &entryArrBld[i]; // make Entry* = to the '&' address of entryArrBld
					} // ?? i ends up = 7656, one more than the arraySize of 7655, and two more than the iterations which should be 7654, but 7653 actually shows the last entry (yuma, az)
		  } // end for

		//check result of shortestDistance
		cout << "Identity is: " << closestBucks ;
		
		// return the Entry with the nearest location
		return closestBucks;
		
		

	} // end getNearest

	