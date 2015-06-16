#include "XPlotterSolution.h"
#include "checksumm.h"
#include "ConfigValue.h"
#include <math.h>

// #define cartesian_width  ((23.0f-2.25)*25.4f)
// #define cartesian_height ((23.0f-2.25)*25.4f)
// #define cartesian_depth 0.0f

// smaller
//#define cartesian_width  (610.0f-60.0f)
//#define cartesian_height (612.0f-60.0f)
//#define cartesian_depth 0.0f


XPlotterSolution::XPlotterSolution(Config* config)
{
	// machine size
	// Should count the "moving" size = width of machine minus width of carriage.
    cartesian_width         = config->value(cartesian_width_checksum)->by_default((610.0f-60.0f))->as_number();
    cartesian_height        = config->value(cartesian_height_checksum)->by_default((612.0f-60.0f))->as_number();
    cartesian_depth         = config->value(cartesian_depth_checksum)->by_default(0.0f)->as_number();
}

// magnitude of 2d vector (x,y)
float mag2d(float x, float y) {
	return(sqrtf(x*x + y*y));
}

void XPlotterSolution::cartesian_to_actuator( float cartesian_mm[], float actuator_mm[] ){
	
		// x=0,y=0 is the center
	// x=-cartesian_width/2, y=-cartesian_height/2 is lower left

	// the string length of all strings when the carriage is at the origin:
	float base_distance = 
		mag2d(.5f*(this->cartesian_width), .5f*(this->cartesian_height)/*, this->cartesian_depth*/);
		//0.0f;
	
	float x = cartesian_mm[X_AXIS];
	float y = cartesian_mm[Y_AXIS];
	//float z = cartesian_mm[Z_AXIS];

	
	// a (top left)
	actuator_mm[ALPHA_STEPPER] = -base_distance+mag2d(this->cartesian_width*.5f+x,this->cartesian_height*.5f-y);
	// b (top right)
	actuator_mm[BETA_STEPPER ] = -base_distance+mag2d(this->cartesian_width*.5f-x,this->cartesian_height*.5f-y);
	// c (bottom right)
	actuator_mm[GAMMA_STEPPER] = -base_distance+mag2d(this->cartesian_width*.5f-x,this->cartesian_height*.5f+y);
	// d (bottom left)
	actuator_mm[DELTA_STEPPER] = -base_distance+mag2d(this->cartesian_width*.5f+x,this->cartesian_height*.5f+y);
}

void XPlotterSolution::actuator_to_cartesian( float actuator_mm[], float cartesian_mm[] ){
	float base_distance = 
		mag2d(.5f*(this->cartesian_width), .5f*(this->cartesian_height)/*, this->cartesian_depth*/);

	float a = actuator_mm[0] + base_distance;
	float b = actuator_mm[1] + base_distance;
	// Use only top left (A) and top right (B) string lengths, and machine size to find x/y
	// (Math derives from pythagorean theorem)
	float xprime = (this->cartesian_width * this->cartesian_width + a * a + b * b) / ( 2.0f * this->cartesian_width);
	float yprime = sqrtf(a * a - xprime * xprime);

    cartesian_mm[X_AXIS] = xprime - 0.5f * this->cartesian_width;
    cartesian_mm[Y_AXIS] = 0.5f * this->cartesian_height - yprime;
    cartesian_mm[Z_AXIS] = 0.0F;
}
