#ifndef VMDL_VEHICLE_CABIN_LIGHTS_SPOTLIGHT_H
#define VMDL_VEHICLE_CABIN_LIGHTS_SPOTLIGHT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::lights {
using ParentClass = Model;

/** Spotlight model. */
class Spotlight : public ParentClass {
public:

    Spotlight(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsSharedOn("IsSharedOn", this),
		IsLeftOn("IsLeftOn", this),
		IsRightOn("IsRightOn", this)
    {}

    /**
    * IsSharedOn: sensor
    * Is a shared light across a specific row on
    *
    **/
    DataPointBoolean IsSharedOn;

    /**
    * IsLeftOn: actuator
    * Is light on the left side switched on
    *
    **/
    DataPointBoolean IsLeftOn;

    /**
    * IsRightOn: actuator
    * Is light on the right side switched on
    *
    **/
    DataPointBoolean IsRightOn;

};
} // namespace velocitas::vehicle::cabin::lights
#endif // VMDL_VEHICLE_CABIN_LIGHTS_SPOTLIGHT_H
