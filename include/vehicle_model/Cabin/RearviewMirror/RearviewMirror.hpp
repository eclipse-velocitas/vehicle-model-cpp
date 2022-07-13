#ifndef VMDL_VEHICLE_CABIN_REARVIEWMIRROR_H
#define VMDL_VEHICLE_CABIN_REARVIEWMIRROR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** RearviewMirror model. */
class RearviewMirror : public ParentClass {
public:

    RearviewMirror(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DimmingLevel("DimmingLevel", this)
    {}

    /**
    * DimmingLevel: actuator
    * Dimming level of rearview mirror. 0 = undimmed. 100 = fully dimmed.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 DimmingLevel;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_REARVIEWMIRROR_H
