#ifndef VMDL_VEHICLE_CABIN_SEAT_AIRBAG_H
#define VMDL_VEHICLE_CABIN_SEAT_AIRBAG_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Airbag model. */
class Airbag : public ParentClass {
public:

    Airbag(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsDeployed("IsDeployed", this)
    {}

    /**
    * IsDeployed: sensor
    * Airbag deployment status. True = Airbag deployed. False = Airbag not deployed.
    *
    **/
    DataPointBoolean IsDeployed;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_AIRBAG_H
