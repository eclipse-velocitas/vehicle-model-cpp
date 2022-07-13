#ifndef VMDL_VEHICLE_OBD_O2_H
#define VMDL_VEHICLE_OBD_O2_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** O2 model. */
class O2 : public ParentClass {
public:

    O2(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Voltage("Voltage", this),
		ShortTermFuelTrim("ShortTermFuelTrim", this)
    {}

    /**
    * Voltage: sensor
    * PID 1x (byte A) - Sensor voltage
    *
    * Unit: V
    **/
    DataPointFloat Voltage;

    /**
    * ShortTermFuelTrim: sensor
    * PID 1x (byte B) - Short term fuel trim
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermFuelTrim;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_O2_H
