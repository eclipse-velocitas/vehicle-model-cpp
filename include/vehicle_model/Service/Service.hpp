#ifndef VMDL_VEHICLE_SERVICE_H
#define VMDL_VEHICLE_SERVICE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Service model. */
class Service : public ParentClass {
public:

    Service(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsServiceDue("IsServiceDue", this),
		DistanceToService("DistanceToService", this),
		TimeToService("TimeToService", this)
    {}

    /**
    * IsServiceDue: sensor
    * Indicates if vehicle needs service (of any kind). True = Service needed now or in the near future. False = No known need for service.
    *
    **/
    DataPointBoolean IsServiceDue;

    /**
    * DistanceToService: sensor
    * Remaining distance to service (of any kind). Negative values indicate service overdue.
    *
    * Unit: km
    **/
    DataPointFloat DistanceToService;

    /**
    * TimeToService: sensor
    * Remaining time to service (of any kind). Negative values indicate service overdue.
    *
    * Unit: s
    **/
    DataPointInt32 TimeToService;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_SERVICE_H
