#ifndef VMDL_VEHICLE_CABIN_DOOR_WINDOW_H
#define VMDL_VEHICLE_CABIN_DOOR_WINDOW_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::door {
using ParentClass = Model;

/** Window model. */
class Window : public ParentClass {
public:

    Window(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOpen("IsOpen", this),
		Position("Position", this),
		IsChildLockEngaged("IsChildLockEngaged", this),
		Switch("Switch", this)
    {}

    /**
    * IsOpen: sensor
    * Is window open or closed?
    *
    **/
    DataPointBoolean IsOpen;

    /**
    * Position: sensor
    * Window position. 0 = Fully closed 100 = Fully opened.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Position;

    /**
    * IsChildLockEngaged: sensor
    * Is window child lock engaged. True = Engaged. False = Disengaged.
    *
    **/
    DataPointBoolean IsChildLockEngaged;

    /**
    * Switch: actuator
    * Switch controlling sliding action such as window, sunroof, or blind.
    *
    * Allowed values: INACTIVE, CLOSE, OPEN, ONE_SHOT_CLOSE, ONE_SHOT_OPEN
    **/
    DataPointString Switch;

};
} // namespace velocitas::vehicle::cabin::door
#endif // VMDL_VEHICLE_CABIN_DOOR_WINDOW_H
