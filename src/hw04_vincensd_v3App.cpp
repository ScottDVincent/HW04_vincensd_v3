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
#include "vincensdStarbucks.cpp"
#include <iostream>
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
	vector<Entry> entryVec;
		
	/** Read .csv file into a vector */
	//Open file
	ifstream infile ("..\\resources\\Starbucks_2006.csv");			// pg589 create an an input stream
	
	if (infile.fail()){ 
		cout << "Error opening file" << endl;						// %s\n", "Starbucks_2006.csv"); 
	}

	string line;
	//char next[256];


	//Fill the vector with entry data
	while ( !infile.eof() ) {
		     
		Entry e;		// for each iteration create a new entry vaiable to hold the input values, don't need a cnostructed object
		//Entry* e = new Entry();		// Mikes code: would cause a memory leak as we are not destroying the object at end 
		

/** Mike's code
>>>>>>> change tree.h location
		infile.getline(next, 256, ',');
		string s(next);
		e->identifier = s;

		infile.getline(next, 256, ',');
		e->x = 0.0;//next; //parse next as double

		infile.getline(next, 256, '\n');
		e->y = 0.0;//next; //parse next as a double

		
	}
}
*/

			
			     //stringstream strstr(line);    	// create a strstr of stringstream type for manipulation
				// char word[256];// = new char[256];


				 getline(infile, line, ',');
				 e.identifier = line;

				 infile.get();
				 infile >> e.x;

				 infile.get();
				 infile >> e.y;


				 /**
				 getline(strstr, line, ',') >> e.identifier;

				//stringstream strstr(line);
				// strstr.getline(strstr, word, ',') >> e.identifier;
				 //strstr.get();
				 //strstr >> e -> x;
				 //double d;
				 //strstr >> d;

				 //strstr.get();
				 //strstr >> e -> y;

				 entryVec.push_back(e);

				 strstr.get();
				 strstr >> e.y;
				 */

				 entryVec.push_back(e);	// split the string and add pieces onto back of vector

	}
			   	
		  
		cout << "End reading file" << endl;		

		//Test Some Data to output our results
		// input something // cin >>

/**

		Entry* getNearest(double x, double y) {

		for (int i = 0; i < the_list.size(); i=i+3)	// iterate thru vector
		cout << the_list.at(i) << '\t';				// write vector contents
		cout << the_list.at(i+1) << '\t';
		cout << the_list.at(i+2) << '\t';
		cout << '\n';
		}
*/	
				
	


/**
		// transform vector into array
		
		Entry entryArr[ entryVec.size() ]; 

		for (int i = 0; i < entryVec.size(); i++ ){
			entryArr[i] = entryVec.at(i);

		}


		// randomize entryArr 
	

		// call build to create data structure
 
		vincensdStarbucks.build(&entryArr, entryVec.size() );

	*/	


		/**
		DESTROY object
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
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( hw04_vincensd_v3App, RendererGl )
