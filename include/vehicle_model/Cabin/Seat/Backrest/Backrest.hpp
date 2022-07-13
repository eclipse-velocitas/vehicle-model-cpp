#ifndef VMDL_VEHICLE_CABIN_SEAT_BACKREST_H
#define VMDL_VEHICLE_CABIN_SEAT_BACKREST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Backrest/Lumbar/Lumbar.hpp"
#include "vehicle_model/Cabin/Seat/Backrest/SideBolster/SideBolster.hpp"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Backrest model. */
class Backrest : public ParentClass {
public:

    Backrest(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Recline("Recline", this),
		Lumbar("Lumbar", this),
		SideBolster("SideBolster", this)
    {}

    /**
    * Recline: actuator
    * Backrest recline compared to seat z-axis (seat vertical axis). 0 degrees = Upright/Vertical backrest. Negative degrees for forward recline. Positive degrees for backward recline.
    *
    * Seat z-axis depends on seat tilt. This means that movement of backrest due to seat tilting will not affect Backrest.Recline as long as the angle between Seating and Backrest are constant. Absolute recline relative to vehicle z-axis can be calculated as Tilt + Backrest.Recline.
    *
    * Unit: degrees
    **/
    DataPointFloat Recline;

    /**
    * Lumbar: branch
    * Adjustable lumbar support mechanisms in seats allow the user to change the seat back shape.
    *
    **/
    vehicle::cabin::seat::backrest::Lumbar Lumbar;

    /**
    * SideBolster: branch
    * Backrest side bolster (lumbar side support) settings.
    *
    **/
    vehicle::cabin::seat::backrest::SideBolster SideBolster;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_BACKREST_H
