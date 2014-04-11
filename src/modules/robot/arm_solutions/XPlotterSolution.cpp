#include "XPlotterSolution.h"
#include <math.h>

// #define cartesian_width  ((23.0f-2.25)*25.4f)
// #define cartesian_height ((23.0f-2.25)*25.4f)
// #define cartesian_depth 0.0f

#define cartesian_width  (610.0f-60.0f)
#define cartesian_height (612.0f-60.0f)
#define cartesian_depth 0.0f


// magnitude of 2d vector (x,y)
float mag2d(float x, float y) {
	return(sqrtf(x*x + y*y));
}

void XPlotterSolution::cartesian_to_actuator( float cartesian_mm[], float actuator_mm[] ){
	
		// x=0,y=0 is the center
	// x=-cartesian_width/2, y=-cartesian_height/2 is lower left

	// the string length of all strings when the carriage is at the origin:
	float base_distance = 
		mag2d(.5f*(cartesian_width), .5f*(cartesian_height)/*, cartesian_depth*/);
		//0.0f;
	
	float x = cartesian_mm[X_AXIS];
	float y = cartesian_mm[Y_AXIS];
	//float z = cartesian_mm[Z_AXIS];

	
	// a (top left)
	actuator_mm[ALPHA_STEPPER] = -base_distance+mag2d(cartesian_width*.5f+x,cartesian_height*.5f-y);
	// b (top right)
	actuator_mm[BETA_STEPPER ] = -base_distance+mag2d(cartesian_width*.5f-x,cartesian_height*.5f-y);
	// c (bottom right)
	actuator_mm[GAMMA_STEPPER] = -base_distance+mag2d(cartesian_width*.5f-x,cartesian_height*.5f+y);
	// d (bottom left)
	actuator_mm[DELTA_STEPPER] = -base_distance+mag2d(cartesian_width*.5f+x,cartesian_height*.5f+y);
}

void XPlotterSolution::actuator_to_cartesian( float actuator_mm[], float cartesian_mm[] ){
	// FIXME: implement using actuator_mm

    cartesian_mm[X_AXIS] = 0.0F;
    cartesian_mm[Y_AXIS] = 0.0F;
    cartesian_mm[Z_AXIS] = 0.0F;
}
