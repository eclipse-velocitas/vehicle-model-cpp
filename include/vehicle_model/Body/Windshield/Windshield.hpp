#ifndef VMDL_VEHICLE_BODY_WINDSHIELD_H
#define VMDL_VEHICLE_BODY_WINDSHIELD_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Body/Windshield/WasherFluid/WasherFluid.hpp"
#include "vehicle_model/Body/Windshield/Wiping/Wiping.hpp"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Windshield model. */
class Windshield : public ParentClass {
public:

    Windshield(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Wiping("Wiping", this),
		IsHeatingOn("IsHeatingOn", this),
		WasherFluid("WasherFluid", this)
    {}

    /**
    * Wiping: branch
    * Windshield wiper signals.
    *
    **/
    vehicle::body::windshield::Wiping Wiping;

    /**
    * IsHeatingOn: actuator
    * Windshield heater status. False - off, True - on.
    *
    **/
    DataPointBoolean IsHeatingOn;

    /**
    * WasherFluid: branch
    * Windshield washer fluid signals
    *
    **/
    vehicle::body::windshield::WasherFluid WasherFluid;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_WINDSHIELD_H
