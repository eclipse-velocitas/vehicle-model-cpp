#ifndef VMDL_VEHICLE_BODY_WINDSHIELD_WASHERFLUID_H
#define VMDL_VEHICLE_BODY_WINDSHIELD_WASHERFLUID_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body::windshield {
using ParentClass = Model;

/** WasherFluid model. */
class WasherFluid : public ParentClass {
public:

    WasherFluid(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsLevelLow("IsLevelLow", this),
		Level("Level", this)
    {}

    /**
    * IsLevelLow: sensor
    * Low level indication for washer fluid. True = Level Low. False = Level OK.
    *
    **/
    DataPointBoolean IsLevelLow;

    /**
    * Level: sensor
    * Washer fluid level as a percent. 0 = Empty. 100 = Full.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 Level;

};
} // namespace velocitas::vehicle::body::windshield
#endif // VMDL_VEHICLE_BODY_WINDSHIELD_WASHERFLUID_H
