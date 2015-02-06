#ifndef SCREWXYSOLUTION_H
#define SCREWXYSOLUTION_H
#include "libs/Module.h"
#include "libs/Kernel.h"
#include "BaseSolution.h"
#include "libs/nuts_bolts.h"

#include "libs/Config.h"

class ScrewXYSolution : public BaseSolution {
    public:
        ScrewXYSolution();
        ScrewXYSolution(Config*){};
        void cartesian_to_actuator( float[], float[] );
        void actuator_to_cartesian( float[], float[] );
};

#endif // SCREWXYSOLUTION_H

