#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class hw04_vincensd_v3App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void hw04_vincensd_v3App::setup()
{
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
