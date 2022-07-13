#ifndef VMDL_VEHICLE_BODY_MIRRORS_H
#define VMDL_VEHICLE_BODY_MIRRORS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Mirrors model. */
class Mirrors : public ParentClass {
public:

    Mirrors(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Tilt("Tilt", this),
		Pan("Pan", this),
		IsHeatingOn("IsHeatingOn", this)
    {}

    /**
    * Tilt: actuator
    * Mirror tilt as a percent. 0 = Center Position. 100 = Fully Upward Position. -100 = Fully Downward Position.
    *
    * Value range: [-100, 100]
    * Unit: percent
    **/
    DataPointInt32 Tilt;

    /**
    * Pan: actuator
    * Mirror pan as a percent. 0 = Center Position. 100 = Fully Left Position. -100 = Fully Right Position.
    *
    * Value range: [-100, 100]
    * Unit: percent
    **/
    DataPointInt32 Pan;

    /**
    * IsHeatingOn: actuator
    * Mirror Heater on or off. True = Heater On. False = Heater Off.
    *
    **/
    DataPointBoolean IsHeatingOn;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_MIRRORS_H
