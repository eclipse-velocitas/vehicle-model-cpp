#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_DCDC_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_DCDC_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::tractionbattery {
using ParentClass = Model;

/** DCDC model. */
class DCDC : public ParentClass {
public:

    DCDC(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		PowerLoss("PowerLoss", this),
		Temperature("Temperature", this)
    {}

    /**
    * PowerLoss: sensor
    * Electrical energy lost by power dissipation to heat inside DC/DC converter.
    *
    * Unit: W
    **/
    DataPointFloat PowerLoss;

    /**
    * Temperature: sensor
    * Current temperature of DC/DC converter converting battery high voltage to vehicle low voltage (typically 12 Volts).
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_DCDC_H
