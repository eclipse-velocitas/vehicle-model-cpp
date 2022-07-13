#ifndef VMDL_VEHICLE_BODY_TRUNK_H
#define VMDL_VEHICLE_BODY_TRUNK_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Trunk model. */
class Trunk : public ParentClass {
public:

    Trunk(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOpen("IsOpen", this),
		IsLocked("IsLocked", this)
    {}

    /**
    * IsOpen: actuator
    * Trunk open or closed. True = Open. False = Closed.
    *
    **/
    DataPointBoolean IsOpen;

    /**
    * IsLocked: actuator
    * Is trunk locked or unlocked. True = Locked. False = Unlocked.
    *
    **/
    DataPointBoolean IsLocked;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_TRUNK_H
