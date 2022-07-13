#ifndef VMDL_VEHICLE_CABIN_SEAT_OCCUPANT_H
#define VMDL_VEHICLE_CABIN_SEAT_OCCUPANT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Seat/Occupant/Identifier/Identifier.hpp"

namespace velocitas::vehicle::cabin::seat {
using ParentClass = Model;

/** Occupant model. */
class Occupant : public ParentClass {
public:

    Occupant(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Identifier("Identifier", this)
    {}

    /**
    * Identifier: branch
    * Identifier attributes based on OAuth 2.0.
    *
    **/
    vehicle::cabin::seat::occupant::Identifier Identifier;

};
} // namespace velocitas::vehicle::cabin::seat
#endif // VMDL_VEHICLE_CABIN_SEAT_OCCUPANT_H
