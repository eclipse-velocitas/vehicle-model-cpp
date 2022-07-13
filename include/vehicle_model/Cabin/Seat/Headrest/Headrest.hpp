#ifndef VMDL_VEHICLE_CABIN_SEAT_HEADREST_H
#define VMDL_VEHICLE_CABIN_SEAT_HEADREST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Headrest model. */
class Headrest : public ParentClass {
public:

    Headrest(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Height("Height", this),
		Angle("Angle", this)
    {}

    /**
    * Height: actuator
    * Position of headrest relative to movable range of the head rest. 0 = Bottommost position supported.
    *
    * Value range: [0, ]
    * Unit: mm
    **/
    DataPointUint32 Height;

    /**
    * Angle: actuator
    * Headrest angle, relative to backrest, 0 degrees if parallel to backrest, Positive degrees = tilted forward.
    *
    * Unit: degrees
    **/
    DataPointFloat Angle;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_HEADREST_H
