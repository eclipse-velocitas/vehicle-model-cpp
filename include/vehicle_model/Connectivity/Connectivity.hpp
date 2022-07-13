#ifndef VMDL_VEHICLE_CONNECTIVITY_H
#define VMDL_VEHICLE_CONNECTIVITY_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Connectivity model. */
class Connectivity : public ParentClass {
public:

    Connectivity(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsConnectivityAvailable("IsConnectivityAvailable", this)
    {}

    /**
    * IsConnectivityAvailable: sensor
    * Indicates if connectivity between vehicle and cloud is available. True = Connectivity is available. False = Connectivity is not available.
    *
    * This signal can be used by onboard vehicle services to decide what features that shall be offered to the driver, for example disable the 'check for update' button if vehicle does not have connectivity.
    *
    **/
    DataPointBoolean IsConnectivityAvailable;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_CONNECTIVITY_H
