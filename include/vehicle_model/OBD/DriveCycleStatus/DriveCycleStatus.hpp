#ifndef VMDL_VEHICLE_OBD_DRIVECYCLESTATUS_H
#define VMDL_VEHICLE_OBD_DRIVECYCLESTATUS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::obd {
using ParentClass = Model;

/** DriveCycleStatus model. */
class DriveCycleStatus : public ParentClass {
public:

    DriveCycleStatus(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsMILOn("IsMILOn", this),
		DTCCount("DTCCount", this),
		IgnitionType("IgnitionType", this)
    {}

    /**
    * IsMILOn: sensor
    * Malfunction Indicator Light (MIL) - False = Off, True = On
    *
    **/
    DataPointBoolean IsMILOn;

    /**
    * DTCCount: sensor
    * Number of sensor Trouble Codes (DTC)
    *
    **/
    DataPointUint32 DTCCount;

    /**
    * IgnitionType: sensor
    * Type of the ignition for ICE - spark = spark plug ignition, compression = self-igniting (Diesel engines)
    *
    * Allowed values: SPARK, COMPRESSION
    **/
    DataPointString IgnitionType;

};
} // namespace velocitas::vehicle::obd
#endif // VMDL_VEHICLE_OBD_DRIVECYCLESTATUS_H
