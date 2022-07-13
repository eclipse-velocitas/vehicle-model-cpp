#ifndef VMDL_VEHICLE_ANGULARVELOCITY_H
#define VMDL_VEHICLE_ANGULARVELOCITY_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** AngularVelocity model. */
class AngularVelocity : public ParentClass {
public:

    AngularVelocity(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Roll("Roll", this),
		Pitch("Pitch", this),
		Yaw("Yaw", this)
    {}

    /**
    * Roll: sensor
    * Vehicle rotation rate along X (longitudinal).
    *
    * Unit: degrees/s
    **/
    DataPointFloat Roll;

    /**
    * Pitch: sensor
    * Vehicle rotation rate along Y (lateral).
    *
    * Unit: degrees/s
    **/
    DataPointFloat Pitch;

    /**
    * Yaw: sensor
    * Vehicle rotation rate along Z (vertical).
    *
    * Unit: degrees/s
    **/
    DataPointFloat Yaw;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_ANGULARVELOCITY_H
