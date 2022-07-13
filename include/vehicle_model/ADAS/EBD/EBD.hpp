#ifndef VMDL_VEHICLE_ADAS_EBD_H
#define VMDL_VEHICLE_ADAS_EBD_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** EBD model. */
class EBD : public ParentClass {
public:

    EBD(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsError("IsError", this),
		IsEngaged("IsEngaged", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if EBD is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsError: sensor
    * Indicates if EBD incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

    /**
    * IsEngaged: sensor
    * Indicates if EBD is currently regulating vehicle brakeforce distribution. True = Engaged. False = Not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_EBD_H
