#ifndef VMDL_VEHICLE_CHASSIS_ACCELERATOR_H
#define VMDL_VEHICLE_CHASSIS_ACCELERATOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** Accelerator model. */
class Accelerator : public ParentClass {
public:

    Accelerator(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		PedalPosition("PedalPosition", this)
    {}

    /**
    * PedalPosition: sensor
    * Accelerator pedal position as percent. 0 = Not depressed. 100 = Fully depressed.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 PedalPosition;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_ACCELERATOR_H
