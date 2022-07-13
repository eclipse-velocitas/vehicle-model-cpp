#ifndef VMDL_VEHICLE_ADAS_TCS_H
#define VMDL_VEHICLE_ADAS_TCS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** TCS model. */
class TCS : public ParentClass {
public:

    TCS(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsError("IsError", this),
		IsEngaged("IsEngaged", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if TCS is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsError: sensor
    * Indicates if TCS incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

    /**
    * IsEngaged: sensor
    * Indicates if TCS is currently regulating traction. True = Engaged. False = Not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_TCS_H
