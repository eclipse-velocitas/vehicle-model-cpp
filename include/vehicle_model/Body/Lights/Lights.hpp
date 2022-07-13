#ifndef VMDL_VEHICLE_BODY_LIGHTS_H
#define VMDL_VEHICLE_BODY_LIGHTS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Lights model. */
class Lights : public ParentClass {
public:

    Lights(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsHighBeamOn("IsHighBeamOn", this),
		IsLowBeamOn("IsLowBeamOn", this),
		IsRunningOn("IsRunningOn", this),
		IsBackupOn("IsBackupOn", this),
		IsParkingOn("IsParkingOn", this),
		IsBrakeOn("IsBrakeOn", this),
		IsRearFogOn("IsRearFogOn", this),
		IsFrontFogOn("IsFrontFogOn", this),
		IsHazardOn("IsHazardOn", this),
		IsLeftIndicatorOn("IsLeftIndicatorOn", this),
		IsRightIndicatorOn("IsRightIndicatorOn", this)
    {}

    /**
    * IsHighBeamOn: actuator
    * Is high beam on?
    *
    **/
    DataPointBoolean IsHighBeamOn;

    /**
    * IsLowBeamOn: actuator
    * Is low beam on?
    *
    **/
    DataPointBoolean IsLowBeamOn;

    /**
    * IsRunningOn: actuator
    * Are running lights on?
    *
    **/
    DataPointBoolean IsRunningOn;

    /**
    * IsBackupOn: actuator
    * Is backup (reverse) light on?
    *
    **/
    DataPointBoolean IsBackupOn;

    /**
    * IsParkingOn: actuator
    * Is parking light on?
    *
    **/
    DataPointBoolean IsParkingOn;

    /**
    * IsBrakeOn: actuator
    * Is brake light on?
    *
    **/
    DataPointBoolean IsBrakeOn;

    /**
    * IsRearFogOn: actuator
    * Is rear fog light on?
    *
    **/
    DataPointBoolean IsRearFogOn;

    /**
    * IsFrontFogOn: actuator
    * Is front fog light on?
    *
    **/
    DataPointBoolean IsFrontFogOn;

    /**
    * IsHazardOn: actuator
    * Are hazards on?
    *
    **/
    DataPointBoolean IsHazardOn;

    /**
    * IsLeftIndicatorOn: actuator
    * Is left indicator flashing?
    *
    **/
    DataPointBoolean IsLeftIndicatorOn;

    /**
    * IsRightIndicatorOn: actuator
    * Is right indicator flashing?
    *
    **/
    DataPointBoolean IsRightIndicatorOn;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_LIGHTS_H
