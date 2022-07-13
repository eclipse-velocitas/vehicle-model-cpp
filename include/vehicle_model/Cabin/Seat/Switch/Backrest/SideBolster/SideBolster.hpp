#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_SIDEBOLSTER_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_SIDEBOLSTER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_::backrest {
using ParentClass = Model;

/** SideBolster model. */
class SideBolster : public ParentClass {
public:

    SideBolster(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsMoreSupportEngaged("IsMoreSupportEngaged", this),
		IsLessSupportEngaged("IsLessSupportEngaged", this)
    {}

    /**
    * IsMoreSupportEngaged: actuator
    * Is switch for more side bolster support engaged (SingleSeat.Backrest.SideBolster.Support).
    *
    **/
    DataPointBoolean IsMoreSupportEngaged;

    /**
    * IsLessSupportEngaged: actuator
    * Is switch for less side bolster support engaged (SingleSeat.Backrest.SideBolster.Support).
    *
    **/
    DataPointBoolean IsLessSupportEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_::backrest
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_SIDEBOLSTER_H
