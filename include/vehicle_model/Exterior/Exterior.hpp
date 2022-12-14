#ifndef VMDL_VEHICLE_EXTERIOR_H
#define VMDL_VEHICLE_EXTERIOR_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Exterior model. */
class Exterior : public ParentClass {
public:

    Exterior(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		AirTemperature("AirTemperature", this),
		Humidity("Humidity", this),
		LightIntensity("LightIntensity", this)
    {}

    /**
    * AirTemperature: sensor
    * Air temperature outside the vehicle.
    *
    * Unit: celsius
    **/
    DataPointFloat AirTemperature;

    /**
    * Humidity: sensor
    * Relative humidity outside the vehicle. 0 = Dry, 100 = Air fully saturated.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat Humidity;

    /**
    * LightIntensity: sensor
    * Light intensity outside the vehicle. 0 = No light detected, 100 = Fully lit.
    *
    * Mapping to physical units and calculation method is sensor specific.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat LightIntensity;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_EXTERIOR_H
