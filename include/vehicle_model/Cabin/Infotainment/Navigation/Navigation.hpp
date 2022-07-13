#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_NAVIGATION_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_NAVIGATION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Infotainment/Navigation/DestinationSet/DestinationSet.hpp"

namespace velocitas::vehicle::cabin::infotainment {
using ParentClass = Model;

/** Navigation model. */
class Navigation : public ParentClass {
public:

    Navigation(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		DestinationSet("DestinationSet", this)
    {}

    /**
    * DestinationSet: branch
    * A navigation has been selected.
    *
    **/
    vehicle::cabin::infotainment::navigation::DestinationSet DestinationSet;

};
} // namespace velocitas::vehicle::cabin::infotainment
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_NAVIGATION_H
