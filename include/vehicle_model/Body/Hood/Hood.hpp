#ifndef VMDL_VEHICLE_BODY_HOOD_H
#define VMDL_VEHICLE_BODY_HOOD_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Hood model. */
class Hood : public ParentClass {
public:

    Hood(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOpen("IsOpen", this)
    {}

    /**
    * IsOpen: actuator
    * Hood open or closed. True = Open. False = Closed.
    *
    **/
    DataPointBoolean IsOpen;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_HOOD_H
