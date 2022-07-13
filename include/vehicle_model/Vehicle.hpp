#ifndef VMDL_VEHICLE_H
#define VMDL_VEHICLE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/ADAS/ADAS.hpp"
#include "vehicle_model/Acceleration/Acceleration.hpp"
#include "vehicle_model/AngularVelocity/AngularVelocity.hpp"
#include "vehicle_model/Body/Body.hpp"
#include "vehicle_model/Cabin/Cabin.hpp"
#include "vehicle_model/Chassis/Chassis.hpp"
#include "vehicle_model/Connectivity/Connectivity.hpp"
#include "vehicle_model/CurrentLocation/CurrentLocation.hpp"
#include "vehicle_model/Driver/Driver.hpp"
#include "vehicle_model/Exterior/Exterior.hpp"
#include "vehicle_model/OBD/OBD.hpp"
#include "vehicle_model/Powertrain/Powertrain.hpp"
#include "vehicle_model/Service/Service.hpp"
#include "vehicle_model/Trailer/Trailer.hpp"
#include "vehicle_model/VehicleIdentification/VehicleIdentification.hpp"
#include "vehicle_model/VersionVSS/VersionVSS.hpp"

namespace velocitas {
using ParentClass = Model;

/** Vehicle model. */
class Vehicle : public ParentClass {
public:

    Vehicle() :
        ParentClass("Vehicle"),
		VersionVSS("VersionVSS", this),
		VehicleIdentification("VehicleIdentification", this),
		LowVoltageSystemState("LowVoltageSystemState", this),
		Speed("Speed", this),
		TravelledDistance("TravelledDistance", this),
		TripMeterReading("TripMeterReading", this),
		IsBrokenDown("IsBrokenDown", this),
		IsMoving("IsMoving", this),
		AverageSpeed("AverageSpeed", this),
		Acceleration("Acceleration", this),
		AngularVelocity("AngularVelocity", this),
		RoofLoad("RoofLoad", this),
		CargoVolume("CargoVolume", this),
		EmissionsCO2("EmissionsCO2", this),
		CurrentOverallWeight("CurrentOverallWeight", this),
		CurbWeight("CurbWeight", this),
		GrossWeight("GrossWeight", this),
		MaxTowWeight("MaxTowWeight", this),
		MaxTowBallWeight("MaxTowBallWeight", this),
		Length("Length", this),
		Height("Height", this),
		Width("Width", this),
		Trailer("Trailer", this),
		CurrentLocation("CurrentLocation", this),
		Powertrain("Powertrain", this),
		Body("Body", this),
		Cabin("Cabin", this),
		ADAS("ADAS", this),
		Chassis("Chassis", this),
		OBD("OBD", this),
		Driver("Driver", this),
		Exterior("Exterior", this),
		Service("Service", this),
		Connectivity("Connectivity", this)
    {}

    /**
    * VersionVSS: branch
    * Supported Version of VSS.
    *
    **/
    vehicle::VersionVSS VersionVSS;

    /**
    * VehicleIdentification: branch
    * Attributes that identify a vehicle.
    *
    **/
    vehicle::VehicleIdentification VehicleIdentification;

    /**
    * LowVoltageSystemState: sensor
    * State of the supply voltage of the control units (usually 12V).
    *
    * Allowed values: UNDEFINED, LOCK, OFF, ACC, ON, START
    **/
    DataPointString LowVoltageSystemState;

    /**
    * Speed: sensor
    * Vehicle speed.
    *
    * Unit: km/h
    **/
    DataPointFloat Speed;

    /**
    * TravelledDistance: sensor
    * Odometer reading, total distance travelled during the lifetime of the vehicle.
    *
    * Unit: km
    **/
    DataPointFloat TravelledDistance;

    /**
    * TripMeterReading: sensor
    * Current trip meter reading.
    *
    * Unit: km
    **/
    DataPointFloat TripMeterReading;

    /**
    * IsBrokenDown: sensor
    * Vehicle breakdown or any similar event causing vehicle to stop on the road, that might pose a risk to other road users. True = Vehicle broken down on the road, due to e.g. engine problems, flat tire, out of gas, brake problems. False = Vehicle not broken down.
    *
    * Actual criteria and method used to decide if a vehicle is broken down is implementation specific.
    *
    **/
    DataPointBoolean IsBrokenDown;

    /**
    * IsMoving: sensor
    * Indicates whether the vehicle is stationary or moving.
    *
    **/
    DataPointBoolean IsMoving;

    /**
    * AverageSpeed: sensor
    * Average speed for the current trip.
    *
    * Unit: km/h
    **/
    DataPointFloat AverageSpeed;

    /**
    * Acceleration: branch
    * Spatial acceleration. Axis definitions according to ISO 8855.
    *
    **/
    vehicle::Acceleration Acceleration;

    /**
    * AngularVelocity: branch
    * Spatial rotation. Axis definitions according to ISO 8855.
    *
    **/
    vehicle::AngularVelocity AngularVelocity;

    /**
    * RoofLoad: attribute (int16)
    * The permitted total weight of cargo and installations (e.g. a roof rack) on top of the vehicle.
    *
    * Unit: kg
    **/
    DataPointInt32 RoofLoad;

    /**
    * CargoVolume: attribute (float)
    * The available volume for cargo or luggage. For automobiles, this is usually the trunk volume.
    *
    * Value range: [0, ]
    * Unit: l
    **/
    DataPointFloat CargoVolume;

    /**
    * EmissionsCO2: attribute (int16)
    * The CO2 emissions.
    *
    * Unit: g/km
    **/
    DataPointInt32 EmissionsCO2;

    /**
    * CurrentOverallWeight: sensor
    * Current overall Vehicle weight. Including passengers, cargo and other load inside the car.
    *
    * Unit: kg
    **/
    DataPointUint32 CurrentOverallWeight;

    /**
    * CurbWeight: attribute (uint16)
    * Vehicle curb weight, including all liquids and full tank of fuel, but no cargo or passengers.
    *
    * Unit: kg
    **/
    DataPointUint32 CurbWeight;

    /**
    * GrossWeight: attribute (uint16)
    * Curb weight of vehicle, including all liquids and full tank of fuel and full load of cargo and passengers.
    *
    * Unit: kg
    **/
    DataPointUint32 GrossWeight;

    /**
    * MaxTowWeight: attribute (uint16)
    * Maximum weight of trailer.
    *
    * Unit: kg
    **/
    DataPointUint32 MaxTowWeight;

    /**
    * MaxTowBallWeight: attribute (uint16)
    * Maximum vertical weight on the tow ball of a trailer.
    *
    * Unit: kg
    **/
    DataPointUint32 MaxTowBallWeight;

    /**
    * Length: attribute (uint16)
    * Overall vehicle length.
    *
    * Unit: mm
    **/
    DataPointUint32 Length;

    /**
    * Height: attribute (uint16)
    * Overall vehicle height.
    *
    * Unit: mm
    **/
    DataPointUint32 Height;

    /**
    * Width: attribute (uint16)
    * Overall vehicle width.
    *
    * Unit: mm
    **/
    DataPointUint32 Width;

    /**
    * Trailer: branch
    * Trailer signals.
    *
    **/
    vehicle::Trailer Trailer;

    /**
    * CurrentLocation: branch
    * The current latitude and longitude of the vehicle.
    *
    **/
    vehicle::CurrentLocation CurrentLocation;

    /**
    * Powertrain: branch
    * Powertrain data for battery management, etc.
    *
    **/
    vehicle::Powertrain Powertrain;

    /**
    * Body: branch
    * All body components.
    *
    **/
    vehicle::Body Body;

    /**
    * Cabin: branch
    * All in-cabin components, including doors.
    *
    **/
    vehicle::Cabin Cabin;

    /**
    * ADAS: branch
    * All Advanced Driver Assist Systems data.
    *
    **/
    vehicle::ADAS ADAS;

    /**
    * Chassis: branch
    * All data concerning steering, suspension, wheels, and brakes.
    *
    **/
    vehicle::Chassis Chassis;

    /**
    * OBD: branch
    * OBD data.
    *
    **/
    vehicle::OBD OBD;

    /**
    * Driver: branch
    * Driver data.
    *
    **/
    vehicle::Driver Driver;

    /**
    * Exterior: branch
    * Information about exterior measured by vehicle.
    *
    **/
    vehicle::Exterior Exterior;

    /**
    * Service: branch
    * Service data.
    *
    **/
    vehicle::Service Service;

    /**
    * Connectivity: branch
    * Connectivity data.
    *
    **/
    vehicle::Connectivity Connectivity;

};
} // namespace velocitas
#endif // VMDL_VEHICLE_H
