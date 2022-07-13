#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_TIMER_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_TIMER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery::charging {
using ParentClass = Model;

/** Timer model. */
class Timer : public ParentClass {
public:

    Timer(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Mode("Mode", this),
		Time("Time", this)
    {}

    /**
    * Mode: actuator
    * Defines timer mode for charging: INACTIVE - no timer set, charging may start as soon as battery is connected to a charger. START_TIME - charging shall start at Charging.Timer.Time. END_TIME - charging shall be finished (reach Charging.ChargeLimit) at Charging.Timer.Time. When charging is completed the vehicle shall change mode to 'inactive' or set a new Charging.Timer.Time. Charging shall start immediately if mode is 'starttime' or 'endtime' and Charging.Timer.Time is a time in the past.
    *
    * Allowed values: INACTIVE, START_TIME, END_TIME
    **/
    DataPointString Mode;

    /**
    * Time: actuator
    * Time for next charging-related action, formatted according to ISO 8601 with UTC time zone. Value has no significance if Charging.Timer.Mode is 'inactive'.
    *
    **/
    DataPointString Time;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery::charging
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_TIMER_H
