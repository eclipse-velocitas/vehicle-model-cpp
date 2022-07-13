#ifndef VMDL_VEHICLE_CABIN_DOOR_H
#define VMDL_VEHICLE_CABIN_DOOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Door/Shade/Shade.hpp"
#include "vehicle_model/Cabin/Door/Window/Window.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Door model. */
class Door : public ParentClass {
public:

    Door(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOpen("IsOpen", this),
		IsLocked("IsLocked", this),
		Window("Window", this),
		IsChildLockActive("IsChildLockActive", this),
		Shade("Shade", this)
    {}

    /**
    * IsOpen: actuator
    * Is door open or closed
    *
    **/
    DataPointBoolean IsOpen;

    /**
    * IsLocked: actuator
    * Is door locked or unlocked. True = Locked. False = Unlocked.
    *
    **/
    DataPointBoolean IsLocked;

    /**
    * Window: branch
    * Door window status
    *
    **/
    vehicle::cabin::door::Window Window;

    /**
    * IsChildLockActive: sensor
    * Is door child lock engaged. True = Engaged. False = Disengaged.
    *
    **/
    DataPointBoolean IsChildLockActive;

    /**
    * Shade: branch
    * Side window shade
    *
    **/
    vehicle::cabin::door::Shade Shade;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_DOOR_H
