#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_SEATING_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_SEATING_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_ {
using ParentClass = Model;

/** Seating model. */
class Seating : public ParentClass {
public:

    Seating(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsForwardEngaged("IsForwardEngaged", this),
		IsBackwardEngaged("IsBackwardEngaged", this)
    {}

    /**
    * IsForwardEngaged: actuator
    * Is switch to increase seating length engaged (SingleSeat.Seating.Length).
    *
    **/
    DataPointBoolean IsForwardEngaged;

    /**
    * IsBackwardEngaged: actuator
    * Is switch to decrease seating length engaged (SingleSeat.Seating.Length).
    *
    **/
    DataPointBoolean IsBackwardEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_SEATING_H
