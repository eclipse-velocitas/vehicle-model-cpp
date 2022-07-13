#ifndef VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_TIRE_H
#define VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_TIRE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis::axle::wheel {
using ParentClass = Model;

/** Tire model. */
class Tire : public ParentClass {
public:

    Tire(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Pressure("Pressure", this),
		IsPressureLow("IsPressureLow", this),
		Temperature("Temperature", this)
    {}

    /**
    * Pressure: sensor
    * Tire pressure in kilo-Pascal.
    *
    * Unit: kPa
    **/
    DataPointUint32 Pressure;

    /**
    * IsPressureLow: sensor
    * Tire Pressure Status. True = Low tire pressure. False = Good tire pressure.
    *
    **/
    DataPointBoolean IsPressureLow;

    /**
    * Temperature: sensor
    * Tire temperature in Celsius.
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature;

};
} // namespace velocitas::vehicle::chassis::axle::wheel
#endif // VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_TIRE_H
