#ifndef VMDL_VEHICLE_ADAS_LANEDEPARTUREDETECTION_H
#define VMDL_VEHICLE_ADAS_LANEDEPARTUREDETECTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** LaneDepartureDetection model. */
class LaneDepartureDetection : public ParentClass {
public:

    LaneDepartureDetection(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsWarning("IsWarning", this),
		IsError("IsError", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if lane departure detection system is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsWarning: sensor
    * Indicates if lane departure detection registered a lane departure.
    *
    **/
    DataPointBoolean IsWarning;

    /**
    * IsError: sensor
    * Indicates if lane departure system incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_LANEDEPARTUREDETECTION_H
