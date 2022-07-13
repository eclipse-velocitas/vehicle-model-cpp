#ifndef VMDL_VEHICLE_DRIVER_IDENTIFIER_H
#define VMDL_VEHICLE_DRIVER_IDENTIFIER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::driver {
using ParentClass = Model;

/** Identifier model. */
class Identifier : public ParentClass {
public:

    Identifier(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Subject("Subject", this),
		Issuer("Issuer", this)
    {}

    /**
    * Subject: sensor
    * Subject for the authentication of the occupant. E.g. UserID 7331677.
    *
    **/
    DataPointString Subject;

    /**
    * Issuer: sensor
    * Unique Issuer for the authentication of the occupant. E.g. https://accounts.funcorp.com.
    *
    **/
    DataPointString Issuer;

};
} // namespace velocitas::vehicle::driver
#endif // VMDL_VEHICLE_DRIVER_IDENTIFIER_H
