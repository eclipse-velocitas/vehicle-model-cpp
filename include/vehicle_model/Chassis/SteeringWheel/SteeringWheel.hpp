#ifndef VMDL_VEHICLE_CHASSIS_STEERINGWHEEL_H
#define VMDL_VEHICLE_CHASSIS_STEERINGWHEEL_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** SteeringWheel model. */
class SteeringWheel : public ParentClass {
public:

    SteeringWheel(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Angle("Angle", this),
		Tilt("Tilt", this),
		Extension("Extension", this),
		Position("Position", this)
    {}

    /**
    * Angle: sensor
    * Steering wheel angle. Positive = degrees to the left. Negative = degrees to the right.
    *
    * Unit: degrees
    **/
    DataPointInt32 Angle;

    /**
    * Tilt: actuator
    * Steering wheel column tilt. 0 = Lowest position. 100 = Highest position.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Tilt;

    /**
    * Extension: actuator
    * Steering wheel column extension from dashboard. 0 = Closest to dashboard. 100 = Furthest from dashboard.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Extension;

    /**
    * Position: attribute (string)
    * Position of the steering wheel on the left or right side of the vehicle.
    *
    * Allowed values: FRONT_LEFT, FRONT_RIGHT
    **/
    DataPointString Position;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_STEERINGWHEEL_H
