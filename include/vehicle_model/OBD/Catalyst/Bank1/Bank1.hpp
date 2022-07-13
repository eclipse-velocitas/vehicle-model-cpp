#ifndef VMDL_VEHICLE_OBD_CATALYST_BANK1_H
#define VMDL_VEHICLE_OBD_CATALYST_BANK1_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd::catalyst {
using ParentClass = Model;

/** Bank1 model. */
class Bank1 : public ParentClass {
public:

    Bank1(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Temperature1("Temperature1", this),
		Temperature2("Temperature2", this)
    {}

    /**
    * Temperature1: sensor
    * PID 3C - Catalyst temperature from bank 1, sensor 1
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature1;

    /**
    * Temperature2: sensor
    * PID 3E - Catalyst temperature from bank 1, sensor 2
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature2;

};
} // namespace velocitas::vehicle::obd::catalyst
#endif // VMDL_VEHICLE_OBD_CATALYST_BANK1_H
