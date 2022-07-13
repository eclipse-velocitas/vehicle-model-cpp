#ifndef VMDL_VEHICLE_DRIVER_H
#define VMDL_VEHICLE_DRIVER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Driver/Identifier/Identifier.hpp"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Driver model. */
class Driver : public ParentClass {
public:

    Driver(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Identifier("Identifier", this),
		DistractionLevel("DistractionLevel", this),
		IsEyesOnRoad("IsEyesOnRoad", this),
		AttentiveProbability("AttentiveProbability", this),
		FatigueLevel("FatigueLevel", this),
		HeartRate("HeartRate", this)
    {}

    /**
    * Identifier: branch
    * Identifier attributes based on OAuth 2.0.
    *
    **/
    vehicle::driver::Identifier Identifier;

    /**
    * DistractionLevel: sensor
    * Distraction level of the driver will be the level how much the driver is distracted, by multiple factors. E.g. Driving situation, acustical or optical signales inside the cockpit, phone calls.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat DistractionLevel;

    /**
    * IsEyesOnRoad: sensor
    * Has driver the eyes on road or not?
    *
    **/
    DataPointBoolean IsEyesOnRoad;

    /**
    * AttentiveProbability: sensor
    * Probability of attentiveness of the driver.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat AttentiveProbability;

    /**
    * FatigueLevel: sensor
    * Fatigueness level of driver. Evaluated by multiple factors like trip time, behaviour of steering, eye status.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat FatigueLevel;

    /**
    * HeartRate: sensor
    * Heart rate of the driver.
    *
    **/
    DataPointUint32 HeartRate;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_DRIVER_H
