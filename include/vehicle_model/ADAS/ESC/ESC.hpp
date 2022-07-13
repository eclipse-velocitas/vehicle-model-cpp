#ifndef VMDL_VEHICLE_ADAS_ESC_H
#define VMDL_VEHICLE_ADAS_ESC_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/ADAS/ESC/RoadFriction/RoadFriction.hpp"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** ESC model. */
class ESC : public ParentClass {
public:

    ESC(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsError("IsError", this),
		IsEngaged("IsEngaged", this),
		IsStrongCrossWindDetected("IsStrongCrossWindDetected", this),
		RoadFriction("RoadFriction", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if ESC is enabled. True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsError: sensor
    * Indicates if ESC incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

    /**
    * IsEngaged: sensor
    * Indicates if ESC is currently regulating vehicle stability. True = Engaged. False = Not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

    /**
    * IsStrongCrossWindDetected: sensor
    * Indicates if the ESC system is detecting strong cross winds. True = Strong cross winds detected. False = No strong cross winds detected.
    *
    **/
    DataPointBoolean IsStrongCrossWindDetected;

    /**
    * RoadFriction: branch
    * Road friction values reported by the ESC system.
    *
    **/
    vehicle::adas::esc::RoadFriction RoadFriction;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_ESC_H
