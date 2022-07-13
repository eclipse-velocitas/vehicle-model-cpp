#ifndef VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_H
#define VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Chassis/Axle/Wheel/Brake/Brake.hpp"
#include "vehicle_model/Chassis/Axle/Wheel/Tire/Tire.hpp"

namespace velocitas::vehicle::chassis::axle {
using ParentClass = Model;

/** Wheel model. */
class Wheel : public ParentClass {
public:

    Wheel(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Brake("Brake", this),
		Tire("Tire", this),
		Speed("Speed", this)
    {}

    /**
    * Brake: branch
    * Brake signals for wheel
    *
    **/
    vehicle::chassis::axle::wheel::Brake Brake;

    /**
    * Tire: branch
    * Tire signals for wheel.
    *
    **/
    vehicle::chassis::axle::wheel::Tire Tire;

    /**
    * Speed: sensor
    * Rotational speed of a vehicle's wheel.
    *
    * Unit: km/h
    **/
    DataPointFloat Speed;

};
} // namespace velocitas::vehicle::chassis::axle
#endif // VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_H
