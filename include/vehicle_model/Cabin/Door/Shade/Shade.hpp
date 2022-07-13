#ifndef VMDL_VEHICLE_CABIN_DOOR_SHADE_H
#define VMDL_VEHICLE_CABIN_DOOR_SHADE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::door {
using ParentClass = Model;

/** Shade model. */
class Shade : public ParentClass {
public:

    Shade(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Switch("Switch", this),
		Position("Position", this)
    {}

    /**
    * Switch: actuator
    * Switch controlling sliding action such as window, sunroof, or blind.
    *
    * Allowed values: INACTIVE, CLOSE, OPEN, ONE_SHOT_CLOSE, ONE_SHOT_OPEN
    **/
    DataPointString Switch;

    /**
    * Position: actuator
    * Position of window blind. 0 = Fully retracted. 100 = Fully deployed.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Position;

};
} // namespace velocitas::vehicle::cabin::door
#endif // VMDL_VEHICLE_CABIN_DOOR_SHADE_H
