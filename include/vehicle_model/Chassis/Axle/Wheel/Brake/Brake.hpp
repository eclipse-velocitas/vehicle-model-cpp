#ifndef VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_BRAKE_H
#define VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_BRAKE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis::axle::wheel {
using ParentClass = Model;

/** Brake model. */
class Brake : public ParentClass {
public:

    Brake(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		FluidLevel("FluidLevel", this),
		IsFluidLevelLow("IsFluidLevelLow", this),
		PadWear("PadWear", this),
		IsBrakesWorn("IsBrakesWorn", this)
    {}

    /**
    * FluidLevel: sensor
    * Brake fluid level as percent. 0 = Empty. 100 = Full.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 FluidLevel;

    /**
    * IsFluidLevelLow: sensor
    * Brake fluid level status. True = Brake fluid level low. False = Brake fluid level OK.
    *
    **/
    DataPointBoolean IsFluidLevelLow;

    /**
    * PadWear: sensor
    * Brake pad wear as percent. 0 = No Wear. 100 = Worn.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 PadWear;

    /**
    * IsBrakesWorn: sensor
    * Brake pad wear status. True = Worn. False = Not Worn.
    *
    **/
    DataPointBoolean IsBrakesWorn;

};
} // namespace velocitas::vehicle::chassis::axle::wheel
#endif // VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_BRAKE_H
