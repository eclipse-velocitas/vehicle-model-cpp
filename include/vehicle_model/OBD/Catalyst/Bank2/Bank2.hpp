#ifndef VMDL_VEHICLE_OBD_CATALYST_BANK2_H
#define VMDL_VEHICLE_OBD_CATALYST_BANK2_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd::catalyst {
using ParentClass = Model;

/** Bank2 model. */
class Bank2 : public ParentClass {
public:

    Bank2(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Temperature1("Temperature1", this),
		Temperature2("Temperature2", this)
    {}

    /**
    * Temperature1: sensor
    * PID 3D - Catalyst temperature from bank 2, sensor 1
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature1;

    /**
    * Temperature2: sensor
    * PID 3F - Catalyst temperature from bank 2, sensor 2
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature2;

};
} // namespace velocitas::vehicle::obd::catalyst
#endif // VMDL_VEHICLE_OBD_CATALYST_BANK2_H
