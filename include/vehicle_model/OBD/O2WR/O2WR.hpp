#ifndef VMDL_VEHICLE_OBD_O2WR_H
#define VMDL_VEHICLE_OBD_O2WR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** O2WR model. */
class O2WR : public ParentClass {
public:

    O2WR(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Lambda("Lambda", this),
		Voltage("Voltage", this),
		Current("Current", this)
    {}

    /**
    * Lambda: sensor
    * PID 2x (byte AB) and PID 3x (byte AB) - Lambda for wide range/band oxygen sensor
    *
    **/
    DataPointFloat Lambda;

    /**
    * Voltage: sensor
    * PID 2x (byte CD) - Voltage for wide range/band oxygen sensor
    *
    * Unit: V
    **/
    DataPointFloat Voltage;

    /**
    * Current: sensor
    * PID 3x (byte CD) - Current for wide range/band oxygen sensor
    *
    * Unit: A
    **/
    DataPointFloat Current;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_O2WR_H
