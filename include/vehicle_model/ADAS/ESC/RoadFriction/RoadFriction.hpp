#ifndef VMDL_VEHICLE_ADAS_ESC_ROADFRICTION_H
#define VMDL_VEHICLE_ADAS_ESC_ROADFRICTION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::adas::esc {
using ParentClass = Model;

/** RoadFriction model. */
class RoadFriction : public ParentClass {
public:

    RoadFriction(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		MostProbable("MostProbable", this),
		LowerBound("LowerBound", this),
		UpperBound("UpperBound", this)
    {}

    /**
    * MostProbable: sensor
    * Most probable road friction, as calculated by the ESC system. Exact meaning of most probable is implementation specific. 0 = no friction, 100 = maximum friction.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat MostProbable;

    /**
    * LowerBound: sensor
    * Lower bound road friction, as calculated by the ESC system. 5% possibility that road friction is below this value. 0 = no friction, 100 = maximum friction.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat LowerBound;

    /**
    * UpperBound: sensor
    * Upper bound road friction, as calculated by the ESC system. 95% possibility that road friction is below this value. 0 = no friction, 100 = maximum friction.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat UpperBound;

};
} // namespace velocitas::vehicle::adas::esc
#endif // VMDL_VEHICLE_ADAS_ESC_ROADFRICTION_H
