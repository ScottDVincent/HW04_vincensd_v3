/*****
 * File: hw04_vincensd_v3App.cpp	
 * Author   : vincensd
 * Date     : 2012-10-10
 * Purpose  :  
 * Sources  : 
 http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/
 http://www.cs.cmu.edu/~awm/animations/kdtree/
 */


//cinder includes
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/Texture.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "cinder/Text.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/Text.h"

//my includes
//#include "vincensdStarbucks.cpp"
#include "vincensdStarbucks.h"

//c++ includes
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>


using namespace ci;
using namespace ci::app;
using namespace std;




class hw04_vincensd_v3App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	//void keyDown( KeyEvent event );
	void update();
	void draw();
	void prepareSettings(Settings* settings);

	private:
	
		//Width and height of the screen
		static const int AppWidth=800;
		static const int AppHeight=600;
		static const int TextureSize=1024; //Must be the next power of 2 bigger or equal to app dimensions
};



void hw04_vincensd_v3App::prepareSettings(Settings* settings){
	settings->setWindowSize(AppWidth,AppHeight);
	settings->setResizable(false);
}



void hw04_vincensd_v3App::setup()
{

	/** setup vars */
	//Entry* e;
	std::vector<Entry> entryVec;
		
	/** Read .csv file into a vector */
	//Open file
	ifstream infile ("..\\resources\\Starbucks_2006.csv");			// pg589 create an an input stream
	
	if (infile.fail()){ 
		cout << "Error opening file" << endl;						// %s\n", "Starbucks_2006.csv"); 
	}

	string line;
	
	//Fill the vector with entry data
	while ( !infile.eof() ) {
		     
		Entry e;		// for each iteration create a new entry vaiable to hold the input values, don't need a cnostructed object
		//Entry* e = new Entry();		// Mikes code: would cause a memory leak as we are not destroying the object at end 
		

				 getline(infile, line, ',');
				 e.identifier = line;

				 infile.get();
				 infile >> e.x;

				 infile.get();
				 infile >> e.y;

				 entryVec.push_back(e);	// split the string and add pieces onto back of vector
	}


	/**CHECK FOR VALID INPUT
		// just look at debugger to see entries
		//	cout << "End reading file" << endl;					
	*/
			   	

	/** REMOVE DUPLCIATES
	// http://en.allexperts.com/q/C-1040/2011/4/remove-duplicates-vector.htm
	*/
		


/**   // transform vector into array
//http://www.cplusplus.com/reference/algorithm/copy/
//http://stackoverflow.com/questions/2923272/how-to-convert-vector-to-array-c
//http://choorucode.wordpress.com/2010/05/25/c-stl-copy-vector-to-array/
// !!!http://bytes.com/topic/c/answers/849132-std-vector-c-array

		
		 /** this wont work as we need to allocate dynamic memory since 
			we aren't calling a contant int for the array size...

		const int entrySize = entryVec.size();
		Entry entryArr [ entrySize ];
		cout << entryVec.size() << endl;	
		*/
		 const int entrySize = entryVec.size();					// size of new array

		 Entry *entryArr = new Entry [ entryVec.size() ];		// have to create a dynamic array of type Entry

		 // copy vector into array
		// std::copy(entryVec.begin(), entryVec.end(), entryArr); 

		/** or ...*/
		for (int i = 0; i < (entryVec.size()-1); i++ ){
			entryArr[i] = entryVec.at(i);
		}
		
		/** test output in Autos window 
		cout << "output = " << &entryArr[0] << endl;
		cout << "output = " << &entryArr[1] << endl;
		cout << "output = " << &entryArr[7654] << endl;
		*/


		// randomize entryArr 
		// !! http://www.fredosaurus.com/notes-cpp/misc/random-shuffle.html
		// http://www.dreamincode.net/code/snippet596.htm
		// http://www.cplusplus.com/reference/algorithm/random_shuffle/
		
		  srand(time(0));  // initialize seed "randomly"
		  for (int i=0; i < (entryVec.size()-1); i++) {
            int r = i + (rand() % (entryVec.size()-i)); // Random remaining position.
            Entry temp = entryArr[i]; 
			entryArr[i] = entryArr[r]; 
			entryArr[r] = temp;
        }

		  /** test output in Autos window*/ 
		cout << "output = " << &entryArr[0] << endl;
		cout << "output = " << &entryArr[1] << endl;
		cout << "output = " << &entryArr[7654] << endl;


		// call build to create data structure
		vincensdStarbucks starObject;
		starObject.build( entryArr, entrySize );	   // correct because of *entryArr, what build is expecting; an Entry* type
		//starObject.build( &entryArr, entrySize ); // this would be incorrect because I already declared entryArr to be a pointer *entryArr 
		//delete [] entryArr;						// on return from build, delete this array and free up memory			
												   // use array in build space to do calculations	
		


/** 	//Entry* getNearest(double x, double y)*/	

		//starObject.getNearest(.405029495, .0869224385); // mcAllen Tx
		starObject.getNearest( 0.213636113, 0.438262 );  // sedona, az
		


		//show object
		cout << "Closets neighbor is: " << starObject.closestBucks -> identifier << endl;

	
		/** DESTROY object
		*/


}

void hw04_vincensd_v3App::mouseDown( MouseEvent event )
{
}

void hw04_vincensd_v3App::update()
{
}

void hw04_vincensd_v3App::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( hw04_vincensd_v3App, RendererGl )
