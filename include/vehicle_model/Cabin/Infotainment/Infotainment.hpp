#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Infotainment/HMI/HMI.hpp"
#include "vehicle_model/Cabin/Infotainment/Media/Media.hpp"
#include "vehicle_model/Cabin/Infotainment/Navigation/Navigation.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Infotainment model. */
class Infotainment : public ParentClass {
public:

    Infotainment(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Media("Media", this),
		Navigation("Navigation", this),
		HMI("HMI", this)
    {}

    /**
    * Media: branch
    * All Media actions
    *
    **/
    vehicle::cabin::infotainment::Media Media;

    /**
    * Navigation: branch
    * All navigation actions
    *
    **/
    vehicle::cabin::infotainment::Navigation Navigation;

    /**
    * HMI: branch
    * HMI related signals
    *
    **/
    vehicle::cabin::infotainment::HMI HMI;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_H
