#ifndef VMDL_VEHICLE_ADAS_OBSTACLEDETECTION_H
#define VMDL_VEHICLE_ADAS_OBSTACLEDETECTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas {
using ParentClass = Model;

/** ObstacleDetection model. */
class ObstacleDetection : public ParentClass {
public:

    ObstacleDetection(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEnabled("IsEnabled", this),
		IsWarning("IsWarning", this),
		IsError("IsError", this)
    {}

    /**
    * IsEnabled: actuator
    * Indicates if obstacle sensor system is enabled (i.e. monitoring for obstacles). True = Enabled. False = Disabled.
    *
    **/
    DataPointBoolean IsEnabled;

    /**
    * IsWarning: sensor
    * Indicates if obstacle sensor system registered an obstacle.
    *
    **/
    DataPointBoolean IsWarning;

    /**
    * IsError: sensor
    * Indicates if obstacle sensor system incurred an error condition. True = Error. False = No Error.
    *
    **/
    DataPointBoolean IsError;

};
} // namespace velocitas::vehicle::adas
#endif // VMDL_VEHICLE_ADAS_OBSTACLEDETECTION_H
