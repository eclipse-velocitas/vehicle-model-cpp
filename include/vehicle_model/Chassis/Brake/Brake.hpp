#ifndef VMDL_VEHICLE_CHASSIS_BRAKE_H
#define VMDL_VEHICLE_CHASSIS_BRAKE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** Brake model. */
class Brake : public ParentClass {
public:

    Brake(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		PedalPosition("PedalPosition", this),
		IsDriverEmergencyBrakingDetected("IsDriverEmergencyBrakingDetected", this)
    {}

    /**
    * PedalPosition: sensor
    * Brake pedal position as percent. 0 = Not depressed. 100 = Fully depressed.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 PedalPosition;

    /**
    * IsDriverEmergencyBrakingDetected: sensor
    * Indicates if emergency braking initiated by driver is detected. True = Emergency braking detected. False = Emergency braking not detected.
    *
    * Detection of emergency braking can trigger Emergency Brake Assist (EBA) to engage.
    *
    **/
    DataPointBoolean IsDriverEmergencyBrakingDetected;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_BRAKE_H
