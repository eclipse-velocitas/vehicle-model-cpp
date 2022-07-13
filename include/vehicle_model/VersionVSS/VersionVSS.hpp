#ifndef VMDL_VEHICLE_VERSIONVSS_H
#define VMDL_VEHICLE_VERSIONVSS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** VersionVSS model. */
class VersionVSS : public ParentClass {
public:

    VersionVSS(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Major("Major", this),
		Minor("Minor", this),
		Patch("Patch", this),
		Label("Label", this)
    {}

    /**
    * Major: attribute (uint32)
    * Supported Version of VSS - Major version.
    *
    **/
    DataPointUint32 Major;

    /**
    * Minor: attribute (uint32)
    * Supported Version of VSS - Minor version.
    *
    **/
    DataPointUint32 Minor;

    /**
    * Patch: attribute (uint32)
    * Supported Version of VSS - Patch version.
    *
    **/
    DataPointUint32 Patch;

    /**
    * Label: attribute (string)
    * Label to further describe the version.
    *
    **/
    DataPointString Label;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_VERSIONVSS_H
