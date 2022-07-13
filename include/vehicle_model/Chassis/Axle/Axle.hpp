#ifndef VMDL_VEHICLE_CHASSIS_AXLE_H
#define VMDL_VEHICLE_CHASSIS_AXLE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Chassis/Axle/Wheel/Wheel.hpp"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** Axle model. */
class Axle : public ParentClass {
public:
    class WheelCollection : public ParentClass {
    public:
        
        WheelCollection(ParentClass* parent):
            ParentClass("Wheel", parent),
            Left("Left", this),
            Right("Right", this)
        {
        }

        vehicle::chassis::axle::Wheel Left;
        vehicle::chassis::axle::Wheel Right;
    };

    Axle(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		WheelCount("WheelCount", this),
		WheelDiameter("WheelDiameter", this),
		WheelWidth("WheelWidth", this),
		TireDiameter("TireDiameter", this),
		TireWidth("TireWidth", this),
		TireAspectRatio("TireAspectRatio", this),
		Wheel(this)
    {}

    /**
    * WheelCount: attribute (uint8)
    * Number of wheels on the axle
    *
    **/
    DataPointUint32 WheelCount;

    /**
    * WheelDiameter: attribute (float)
    * Diameter of wheels (rims without tires), in inches, as per ETRTO / TRA standard.
    *
    * Unit: inch
    **/
    DataPointFloat WheelDiameter;

    /**
    * WheelWidth: attribute (float)
    * Width of wheels (rims without tires), in inches, as per ETRTO / TRA standard.
    *
    * Unit: inch
    **/
    DataPointFloat WheelWidth;

    /**
    * TireDiameter: attribute (float)
    * Outer diameter of tires, in inches, as per ETRTO / TRA standard.
    *
    * Unit: inch
    **/
    DataPointFloat TireDiameter;

    /**
    * TireWidth: attribute (uint16)
    * Nominal section width of tires, in mm, as per ETRTO / TRA standard.
    *
    * Unit: mm
    **/
    DataPointUint32 TireWidth;

    /**
    * TireAspectRatio: attribute (uint8)
    * Aspect ratio between tire section height and tire section width, as per ETRTO / TRA standard.
    *
    * Unit: percent
    **/
    DataPointUint32 TireAspectRatio;

    /**
    * Wheel: branch
    * Wheel signals for axle
    *
    **/
    WheelCollection Wheel;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_AXLE_H
