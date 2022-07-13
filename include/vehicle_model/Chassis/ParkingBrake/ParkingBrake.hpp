#ifndef VMDL_VEHICLE_CHASSIS_PARKINGBRAKE_H
#define VMDL_VEHICLE_CHASSIS_PARKINGBRAKE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** ParkingBrake model. */
class ParkingBrake : public ParentClass {
public:

    ParkingBrake(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEngaged("IsEngaged", this)
    {}

    /**
    * IsEngaged: actuator
    * Parking brake status. True = Parking Brake is Engaged. False = Parking Brake is not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_PARKINGBRAKE_H
