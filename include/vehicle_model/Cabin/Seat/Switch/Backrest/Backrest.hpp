#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Switch/Backrest/Lumbar/Lumbar.hpp"
#include "vehicle_model/Cabin/Seat/Switch/Backrest/SideBolster/SideBolster.hpp"

namespace velocitas::vehicle::cabin::seat::switch_ {
using ParentClass = Model;

/** Backrest model. */
class Backrest : public ParentClass {
public:

    Backrest(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsReclineForwardEngaged("IsReclineForwardEngaged", this),
		IsReclineBackwardEngaged("IsReclineBackwardEngaged", this),
		Lumbar("Lumbar", this),
		SideBolster("SideBolster", this)
    {}

    /**
    * IsReclineForwardEngaged: actuator
    * Backrest recline forward switch engaged (SingleSeat.Backrest.Recline).
    *
    **/
    DataPointBoolean IsReclineForwardEngaged;

    /**
    * IsReclineBackwardEngaged: actuator
    * Backrest recline backward switch engaged (SingleSeat.Backrest.Recline).
    *
    **/
    DataPointBoolean IsReclineBackwardEngaged;

    /**
    * Lumbar: branch
    * Switches for SingleSeat.Backrest.Lumbar.
    *
    **/
    vehicle::cabin::seat::switch_::backrest::Lumbar Lumbar;

    /**
    * SideBolster: branch
    * Switches for SingleSeat.Backrest.SideBolster.
    *
    **/
    vehicle::cabin::seat::switch_::backrest::SideBolster SideBolster;

};
} // namespace velocitas::vehicle::cabin::seat::switch_
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_H
