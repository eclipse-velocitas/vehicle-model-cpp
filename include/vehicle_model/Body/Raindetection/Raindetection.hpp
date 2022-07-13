#ifndef VMDL_VEHICLE_BODY_RAINDETECTION_H
#define VMDL_VEHICLE_BODY_RAINDETECTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Raindetection model. */
class Raindetection : public ParentClass {
public:

    Raindetection(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Intensity("Intensity", this)
    {}

    /**
    * Intensity: sensor
    * Rain intensity. 0 = Dry, No Rain. 100 = Covered.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 Intensity;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_RAINDETECTION_H
