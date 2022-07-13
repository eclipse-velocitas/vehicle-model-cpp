#ifndef VMDL_VEHICLE_CABIN_SEAT_BACKREST_SIDEBOLSTER_H
#define VMDL_VEHICLE_CABIN_SEAT_BACKREST_SIDEBOLSTER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::backrest {
using ParentClass = Model;

/** SideBolster model. */
class SideBolster : public ParentClass {
public:

    SideBolster(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Support("Support", this)
    {}

    /**
    * Support: actuator
    * Side bolster support. 0 = Minimum support (widest side bolster setting). 100 = Maximum support.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat Support;

};
} // namespace velocitas::vehicle::cabin::seat::backrest
#endif // VMDL_VEHICLE_CABIN_SEAT_BACKREST_SIDEBOLSTER_H
