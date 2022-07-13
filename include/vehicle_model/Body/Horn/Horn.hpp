#ifndef VMDL_VEHICLE_BODY_HORN_H
#define VMDL_VEHICLE_BODY_HORN_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Horn model. */
class Horn : public ParentClass {
public:

    Horn(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsActive("IsActive", this)
    {}

    /**
    * IsActive: actuator
    * Horn active or inactive. True = Active. False = Inactive.
    *
    **/
    DataPointBoolean IsActive;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_HORN_H
