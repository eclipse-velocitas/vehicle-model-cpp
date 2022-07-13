#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_NAVIGATION_DESTINATIONSET_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_NAVIGATION_DESTINATIONSET_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::infotainment::navigation {
using ParentClass = Model;

/** DestinationSet model. */
class DestinationSet : public ParentClass {
public:

    DestinationSet(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Latitude("Latitude", this),
		Longitude("Longitude", this)
    {}

    /**
    * Latitude: actuator
    * Latitude of destination in WGS 84 geodetic coordinates.
    *
    * Value range: [-90, 90]
    * Unit: degrees
    **/
    DataPointDouble Latitude;

    /**
    * Longitude: actuator
    * Longitude of destination in WGS 84 geodetic coordinates.
    *
    * Value range: [-180, 180]
    * Unit: degrees
    **/
    DataPointDouble Longitude;

};
} // namespace velocitas::vehicle::cabin::infotainment::navigation
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_NAVIGATION_DESTINATIONSET_H
