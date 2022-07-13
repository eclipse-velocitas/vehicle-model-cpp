#ifndef VMDL_VEHICLE_CABIN_CONVERTIBLE_H
#define VMDL_VEHICLE_CABIN_CONVERTIBLE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Convertible model. */
class Convertible : public ParentClass {
public:

    Convertible(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Status("Status", this)
    {}

    /**
    * Status: sensor
    * Roof status on convertible vehicles.
    *
    * Allowed values: UNDEFINED, CLOSED, OPEN, CLOSING, OPENING, STALLED
    **/
    DataPointString Status;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_CONVERTIBLE_H
