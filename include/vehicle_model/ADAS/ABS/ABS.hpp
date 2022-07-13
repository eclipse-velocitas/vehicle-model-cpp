#ifndef VMDL_VEHICLE_ADAS_ABS_H
#define VMDL_VEHICLE_ADAS_ABS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** ABS model. */
class ABS : public ParentClass {
public:

    ABS(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsError("IsError", this),
		IsEngaged("IsEngaged", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if ABS is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsError: sensor
    * Indicates if ABS incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

    /**
    * IsEngaged: sensor
    * Indicates if ABS is currently regulating brake pressure. True = Engaged. False = Not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_ABS_H
