#ifndef XPLOTTERSOLUTION_H
#define XPLOTTERSOLUTION_H
#include "libs/Module.h"
#include "libs/Kernel.h"
#include "BaseSolution.h"
#include "libs/nuts_bolts.h"

#include "libs/Config.h"

class XPlotterSolution : public BaseSolution {
    public:
        XPlotterSolution();
        XPlotterSolution(Config*){};
        void cartesian_to_actuator( float[], float[] );
        void actuator_to_cartesian( float[], float[] );
};

#endif // XPLOTTERSOLUTION_H

