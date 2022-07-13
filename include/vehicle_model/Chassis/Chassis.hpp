#ifndef VMDL_VEHICLE_CHASSIS_H
#define VMDL_VEHICLE_CHASSIS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Chassis/Accelerator/Accelerator.hpp"
#include "vehicle_model/Chassis/Axle/Axle.hpp"
#include "vehicle_model/Chassis/Brake/Brake.hpp"
#include "vehicle_model/Chassis/ParkingBrake/ParkingBrake.hpp"
#include "vehicle_model/Chassis/SteeringWheel/SteeringWheel.hpp"

#include <stdexcept>

namespace velocitas::vehicle {
using ParentClass = Model;

/** Chassis model. */
class Chassis : public ParentClass {
public:
    class AxleCollection : public ParentClass {
    public:
        
        AxleCollection(ParentClass* parent):
            ParentClass("Axle", parent),
            Row1("Row1", this),
            Row2("Row2", this)
        {
        }

        vehicle::chassis::Axle& Row(int index) {
            if (index == 1) {
                return Row1;
            }
            if (index == 2) {
                return Row2;
            }
            throw std::runtime_error("Given value is outside of allowed range [1;2]!");
        }

        vehicle::chassis::Axle Row1;
        vehicle::chassis::Axle Row2;
    };

    Chassis(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Wheelbase("Wheelbase", this),
		Track("Track", this),
		Axle(this),
		AxleCount("AxleCount", this),
		ParkingBrake("ParkingBrake", this),
		SteeringWheel("SteeringWheel", this),
		Accelerator("Accelerator", this),
		Brake("Brake", this)
    {}

    /**
    * Wheelbase: attribute (uint16)
    * Overall wheel base, in mm.
    *
    * Unit: mm
    **/
    DataPointUint32 Wheelbase;

    /**
    * Track: attribute (uint16)
    * Overall wheel tracking, in mm.
    *
    * Unit: mm
    **/
    DataPointUint32 Track;

    /**
    * Axle: branch
    * Axle signals
    *
    **/
    AxleCollection Axle;

    /**
    * AxleCount: attribute (uint8)
    * Number of axles on the vehicle
    *
    **/
    DataPointUint32 AxleCount;

    /**
    * ParkingBrake: branch
    * Parking brake signals
    *
    **/
    vehicle::chassis::ParkingBrake ParkingBrake;

    /**
    * SteeringWheel: branch
    * Steering wheel signals
    *
    **/
    vehicle::chassis::SteeringWheel SteeringWheel;

    /**
    * Accelerator: branch
    * Accelerator signals
    *
    **/
    vehicle::chassis::Accelerator Accelerator;

    /**
    * Brake: branch
    * Brake system signals
    *
    **/
    vehicle::chassis::Brake Brake;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_CHASSIS_H
