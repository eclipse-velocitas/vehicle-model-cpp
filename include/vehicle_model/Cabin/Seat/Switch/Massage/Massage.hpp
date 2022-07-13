#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_MASSAGE_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_MASSAGE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_ {
using ParentClass = Model;

/** Massage model. */
class Massage : public ParentClass {
public:

    Massage(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsIncreaseEngaged("IsIncreaseEngaged", this),
		IsDecreaseEngaged("IsDecreaseEngaged", this)
    {}

    /**
    * IsIncreaseEngaged: actuator
    * Increase massage level switch engaged (SingleSeat.Massage).
    *
    **/
    DataPointBoolean IsIncreaseEngaged;

    /**
    * IsDecreaseEngaged: actuator
    * Decrease massage level switch engaged (SingleSeat.Massage).
    *
    **/
    DataPointBoolean IsDecreaseEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_MASSAGE_H
