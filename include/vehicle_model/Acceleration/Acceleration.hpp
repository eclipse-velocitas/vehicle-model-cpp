#ifndef VMDL_VEHICLE_ACCELERATION_H
#define VMDL_VEHICLE_ACCELERATION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Acceleration model. */
class Acceleration : public ParentClass {
public:

    Acceleration(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Longitudinal("Longitudinal", this),
		Lateral("Lateral", this),
		Vertical("Vertical", this)
    {}

    /**
    * Longitudinal: sensor
    * Vehicle acceleration in X (longitudinal acceleration).
    *
    * Unit: m/s^2
    **/
    DataPointFloat Longitudinal;

    /**
    * Lateral: sensor
    * Vehicle acceleration in Y (lateral acceleration).
    *
    * Unit: m/s^2
    **/
    DataPointFloat Lateral;

    /**
    * Vertical: sensor
    * Vehicle acceleration in Z (vertical acceleration).
    *
    * Unit: m/s^2
    **/
    DataPointFloat Vertical;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_ACCELERATION_H
