#ifndef XPLOTTERSOLUTION_H
#define XPLOTTERSOLUTION_H
#include "libs/Module.h"
#include "libs/Kernel.h"
#include "BaseSolution.h"
#include "libs/nuts_bolts.h"

#include "libs/Config.h"

#define cartesian_width_checksum         CHECKSUM("zar_cartesian_width")
#define cartesian_height_checksum         CHECKSUM("zar_cartesian_height")
#define cartesian_depth_checksum         CHECKSUM("zar_cartesian_depth")

class XPlotterSolution : public BaseSolution {
    public:
        XPlotterSolution();
        XPlotterSolution(Config*);
        void cartesian_to_actuator( float[], float[] );
        void actuator_to_cartesian( float[], float[] );
    private:
        float cartesian_width;
        float cartesian_height;
        float cartesian_depth;
};

#endif // XPLOTTERSOLUTION_H

