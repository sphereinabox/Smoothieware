#include "ScrewXYSolution.h"
#include <math.h>

const float SCREWXY_RATIO = 20.0/(3.14159265358979 * 7.5);
//const float SCREWXY_RATIO = 0.0;
//(1/(1-ratio*ratio))[1 -ratio -ratio 1]
const float SCREWXY_RATIO_XYZ = 1.0/(1-SCREWXY_RATIO*SCREWXY_RATIO);

void ScrewXYSolution::cartesian_to_actuator( float cartesian_mm[], float actuator_mm[] ){
    actuator_mm[ALPHA_STEPPER] = cartesian_mm[X_AXIS] + +SCREWXY_RATIO*cartesian_mm[Y_AXIS];
    actuator_mm[BETA_STEPPER ] = -SCREWXY_RATIO*cartesian_mm[X_AXIS] + cartesian_mm[Y_AXIS];
    actuator_mm[GAMMA_STEPPER] = cartesian_mm[Z_AXIS];
}

void ScrewXYSolution::actuator_to_cartesian( float actuator_mm[], float cartesian_mm[] ){
    // Not implemented correctly
    cartesian_mm[X_AXIS] = 0.5F * (actuator_mm[ALPHA_STEPPER] + actuator_mm[BETA_STEPPER]);
    cartesian_mm[Y_AXIS] = 0.5F * (actuator_mm[ALPHA_STEPPER] - actuator_mm[BETA_STEPPER]);
    cartesian_mm[Z_AXIS] = actuator_mm[GAMMA_STEPPER];
}
