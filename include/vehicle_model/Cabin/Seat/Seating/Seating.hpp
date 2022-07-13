#ifndef VMDL_VEHICLE_CABIN_SEAT_SEATING_H
#define VMDL_VEHICLE_CABIN_SEAT_SEATING_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Seating model. */
class Seating : public ParentClass {
public:

    Seating(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Length("Length", this)
    {}

    /**
    * Length: actuator
    * Length adjustment of seating. 0 = Adjustable part of seating in rearmost position (Shortest length of seating).
    *
    * Value range: [0, ]
    * Unit: mm
    **/
    DataPointUint32 Length;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_SEATING_H
