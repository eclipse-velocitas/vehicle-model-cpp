#ifndef VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_H
#define VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/CurrentLocation/GNSSReceiver/MountingPosition/MountingPosition.hpp"

namespace velocitas::vehicle::currentlocation {
using ParentClass = Model;

/** GNSSReceiver model. */
class GNSSReceiver : public ParentClass {
public:

    GNSSReceiver(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		FixType("FixType", this),
		MountingPosition("MountingPosition", this)
    {}

    /**
    * FixType: sensor
    * Fix status of GNSS receiver.
    *
    * Allowed values: NONE, TWO_D, TWO_D_SATELLITE_BASED_AUGMENTATION, TWO_D_GROUND_BASED_AUGMENTATION, TWO_D_SATELLITE_AND_GROUND_BASED_AUGMENTATION, THREE_D, THREE_D_SATELLITE_BASED_AUGMENTATION, THREE_D_GROUND_BASED_AUGMENTATION, THREE_D_SATELLITE_AND_GROUND_BASED_AUGMENTATION
    **/
    DataPointString FixType;

    /**
    * MountingPosition: branch
    * Mounting position of GNSS receiver antenna relative to vehicle coordinate system. Axis definitions according to ISO 8855. Origin at center of (first) rear axle.
    *
    **/
    vehicle::currentlocation::gnssreceiver::MountingPosition MountingPosition;

};
} // namespace velocitas::vehicle::currentlocation
#endif // VMDL_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_H
