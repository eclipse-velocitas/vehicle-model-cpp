#ifndef VMDL_VEHICLE_ADAS_CRUISECONTROL_H
#define VMDL_VEHICLE_ADAS_CRUISECONTROL_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** CruiseControl model. */
class CruiseControl : public ParentClass {
public:

    CruiseControl(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsActive("IsActive", this),
		SpeedSet("SpeedSet", this),
		IsError("IsError", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if cruise control system is enabled (e.g. ready to receive configurations and settings) True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsActive: actuator
    * Indicates if cruise control system is active (i.e. actively controls speed). True = Active. False = Inactive.
    *
    **/
    DataPointBoolean IsActive;

    /**
    * SpeedSet: actuator
    * Set cruise control speed in kilometers per hour.
    *
    * Unit: km/h
    **/
    DataPointFloat SpeedSet;

    /**
    * IsError: sensor
    * Indicates if cruise control system incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_CRUISECONTROL_H
