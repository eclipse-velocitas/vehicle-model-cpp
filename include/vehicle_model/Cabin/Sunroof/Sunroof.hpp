#ifndef VMDL_VEHICLE_CABIN_SUNROOF_H
#define VMDL_VEHICLE_CABIN_SUNROOF_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Sunroof/Shade/Shade.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Sunroof model. */
class Sunroof : public ParentClass {
public:

    Sunroof(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Position("Position", this),
		Switch("Switch", this),
		Shade("Shade", this)
    {}

    /**
    * Position: sensor
    * Sunroof position. 0 = Fully closed 100 = Fully opened. -100 = Fully tilted.
    *
    * Value range: [-100, 100]
    **/
    DataPointInt32 Position;

    /**
    * Switch: actuator
    * Switch controlling sliding action such as window, sunroof, or shade.
    *
    * Allowed values: INACTIVE, CLOSE, OPEN, ONE_SHOT_CLOSE, ONE_SHOT_OPEN, TILT_UP, TILT_DOWN
    **/
    DataPointString Switch;

    /**
    * Shade: branch
    * Sun roof shade status.
    *
    **/
    vehicle::cabin::sunroof::Shade Shade;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_SUNROOF_H
