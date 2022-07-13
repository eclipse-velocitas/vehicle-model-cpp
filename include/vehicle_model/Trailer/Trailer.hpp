#ifndef VMDL_VEHICLE_TRAILER_H
#define VMDL_VEHICLE_TRAILER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Trailer model. */
class Trailer : public ParentClass {
public:

    Trailer(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsConnected("IsConnected", this)
    {}

    /**
    * IsConnected: sensor
    * Signal indicating if trailer is connected or not.
    *
    **/
    DataPointBoolean IsConnected;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_TRAILER_H
