#ifndef VMDL_VEHICLE_OBD_CATALYST_H
#define VMDL_VEHICLE_OBD_CATALYST_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/OBD/Catalyst/Bank1/Bank1.hpp"
#include "vehicle_model/OBD/Catalyst/Bank2/Bank2.hpp"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** Catalyst model. */
class Catalyst : public ParentClass {
public:

    Catalyst(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Bank1("Bank1", this),
		Bank2("Bank2", this)
    {}

    /**
    * Bank1: branch
    * Catalyst bank 1 signals
    *
    **/
    vehicle::obd::catalyst::Bank1 Bank1;

    /**
    * Bank2: branch
    * Catalyst bank 2 signals
    *
    **/
    vehicle::obd::catalyst::Bank2 Bank2;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_CATALYST_H
