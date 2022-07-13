#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_STATEOFCHARGE_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_STATEOFCHARGE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery {
using ParentClass = Model;

/** StateOfCharge model. */
class StateOfCharge : public ParentClass {
public:

    StateOfCharge(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Current("Current", this),
		Displayed("Displayed", this)
    {}

    /**
    * Current: sensor
    * Physical state of charge of the high voltage battery, relative to net capacity. This is not necessarily the state of charge being displayed to the customer.
    *
    * Value range: [0, 100.0]
    * Unit: percent
    **/
    DataPointFloat Current;

    /**
    * Displayed: sensor
    * State of charge displayed to the customer.
    *
    * Value range: [0, 100.0]
    * Unit: percent
    **/
    DataPointFloat Displayed;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_STATEOFCHARGE_H
