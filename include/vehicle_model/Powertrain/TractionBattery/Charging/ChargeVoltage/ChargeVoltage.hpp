#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGEVOLTAGE_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGEVOLTAGE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery::charging {
using ParentClass = Model;

/** ChargeVoltage model. */
class ChargeVoltage : public ParentClass {
public:

    ChargeVoltage(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DC("DC", this),
		Phase1("Phase1", this),
		Phase2("Phase2", this),
		Phase3("Phase3", this)
    {}

    /**
    * DC: sensor
    * Current DC charging voltage at charging inlet.
    *
    * Unit: V
    **/
    DataPointFloat DC;

    /**
    * Phase1: sensor
    * Current AC charging voltage (rms) at inlet for Phase 1.
    *
    * Unit: V
    **/
    DataPointFloat Phase1;

    /**
    * Phase2: sensor
    * Current AC charging voltage (rms) at inlet for Phase 2.
    *
    * Unit: V
    **/
    DataPointFloat Phase2;

    /**
    * Phase3: sensor
    * Current AC charging voltage (rms) at inlet for Phase 3.
    *
    * Unit: V
    **/
    DataPointFloat Phase3;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery::charging
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_CHARGEVOLTAGE_H
