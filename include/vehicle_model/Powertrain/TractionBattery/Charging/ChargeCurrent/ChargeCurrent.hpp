#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGECURRENT_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGECURRENT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery::charging {
using ParentClass = Model;

/** ChargeCurrent model. */
class ChargeCurrent : public ParentClass {
public:

    ChargeCurrent(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DC("DC", this),
		Phase1("Phase1", this),
		Phase2("Phase2", this),
		Phase3("Phase3", this)
    {}

    /**
    * DC: sensor
    * Current DC charging current at inlet. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat DC;

    /**
    * Phase1: sensor
    * Current AC charging current (rms) at inlet for Phase 1. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat Phase1;

    /**
    * Phase2: sensor
    * Current AC charging current (rms) at inlet for Phase 2. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat Phase2;

    /**
    * Phase3: sensor
    * Current AC charging current (rms) at inlet for Phase 3. Negative if returning energy to grid.
    *
    * Unit: A
    **/
    DataPointFloat Phase3;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery::charging
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGECURRENT_H
