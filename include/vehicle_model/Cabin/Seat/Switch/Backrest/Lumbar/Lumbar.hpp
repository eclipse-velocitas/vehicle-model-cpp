#ifndef VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_LUMBAR_H
#define VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_LUMBAR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::seat::switch_::backrest {
using ParentClass = Model;

/** Lumbar model. */
class Lumbar : public ParentClass {
public:

    Lumbar(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsMoreSupportEngaged("IsMoreSupportEngaged", this),
		IsLessSupportEngaged("IsLessSupportEngaged", this),
		IsUpEngaged("IsUpEngaged", this),
		IsDownEngaged("IsDownEngaged", this)
    {}

    /**
    * IsMoreSupportEngaged: actuator
    * Is switch for more lumbar support engaged (SingleSeat.Backrest.Lumbar.Support).
    *
    **/
    DataPointBoolean IsMoreSupportEngaged;

    /**
    * IsLessSupportEngaged: actuator
    * Is switch for less lumbar support engaged (SingleSeat.Backrest.Lumbar.Support).
    *
    **/
    DataPointBoolean IsLessSupportEngaged;

    /**
    * IsUpEngaged: actuator
    * Lumbar up switch engaged (SingleSeat.Backrest.Lumbar.Support).
    *
    **/
    DataPointBoolean IsUpEngaged;

    /**
    * IsDownEngaged: actuator
    * Lumbar down switch engaged (SingleSeat.Backrest.Lumbar.Support).
    *
    **/
    DataPointBoolean IsDownEngaged;

};
} // namespace velocitas::vehicle::cabin::seat::switch_::backrest
#endif // VMDL_VEHICLE_CABIN_SEAT_SWITCH_BACKREST_LUMBAR_H
