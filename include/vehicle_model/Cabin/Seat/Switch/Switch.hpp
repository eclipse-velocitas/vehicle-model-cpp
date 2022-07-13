#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Switch/Backrest/Backrest.hpp"
#include "vehicle_model/Cabin/Seat/Switch/Headrest/Headrest.hpp"
#include "vehicle_model/Cabin/Seat/Switch/Massage/Massage.hpp"
#include "vehicle_model/Cabin/Seat/Switch/Seating/Seating.hpp"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Switch model. */
class Switch : public ParentClass {
public:

    Switch(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsWarmerEngaged("IsWarmerEngaged", this),
		IsCoolerEngaged("IsCoolerEngaged", this),
		IsForwardEngaged("IsForwardEngaged", this),
		IsBackwardEngaged("IsBackwardEngaged", this),
		IsUpEngaged("IsUpEngaged", this),
		IsDownEngaged("IsDownEngaged", this),
		IsTiltForwardEngaged("IsTiltForwardEngaged", this),
		IsTiltBackwardEngaged("IsTiltBackwardEngaged", this),
		Backrest("Backrest", this),
		Seating("Seating", this),
		Headrest("Headrest", this),
		Massage("Massage", this)
    {}

    /**
    * IsWarmerEngaged: actuator
    * Warmer switch for Seat heater (SingleSeat.Heating).
    *
    **/
    DataPointBoolean IsWarmerEngaged;

    /**
    * IsCoolerEngaged: actuator
    * Cooler switch for Seat heater (SingleSeat.Heating).
    *
    **/
    DataPointBoolean IsCoolerEngaged;

    /**
    * IsForwardEngaged: actuator
    * Seat forward switch engaged (SingleSeat.Position).
    *
    **/
    DataPointBoolean IsForwardEngaged;

    /**
    * IsBackwardEngaged: actuator
    * Seat backward switch engaged (SingleSeat.Position).
    *
    **/
    DataPointBoolean IsBackwardEngaged;

    /**
    * IsUpEngaged: actuator
    * Seat up switch engaged (SingleSeat.Height).
    *
    **/
    DataPointBoolean IsUpEngaged;

    /**
    * IsDownEngaged: actuator
    * Seat down switch engaged (SingleSeat.Height).
    *
    **/
    DataPointBoolean IsDownEngaged;

    /**
    * IsTiltForwardEngaged: actuator
    * Tilt forward switch engaged (SingleSeat.Tilt).
    *
    **/
    DataPointBoolean IsTiltForwardEngaged;

    /**
    * IsTiltBackwardEngaged: actuator
    * Tilt backward switch engaged (SingleSeat.Tilt).
    *
    **/
    DataPointBoolean IsTiltBackwardEngaged;

    /**
    * Backrest: branch
    * Describes switches related to the backrest of the seat.
    *
    **/
    vehicle::cabin::seat::switch_::Backrest Backrest;

    /**
    * Seating: branch
    * Describes switches related to the seating of the seat.
    *
    **/
    vehicle::cabin::seat::switch_::Seating Seating;

    /**
    * Headrest: branch
    * Switches for SingleSeat.Headrest.
    *
    **/
    vehicle::cabin::seat::switch_::Headrest Headrest;

    /**
    * Massage: branch
    * Switches for SingleSeat.Massage.
    *
    **/
    vehicle::cabin::seat::switch_::Massage Massage;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_H
