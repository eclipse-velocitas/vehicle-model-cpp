#ifndef VMDL_VEHICLE_VEHICLEIDENTIFICATION_H
#define VMDL_VEHICLE_VEHICLEIDENTIFICATION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** VehicleIdentification model. */
class VehicleIdentification : public ParentClass {
public:

    VehicleIdentification(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		VIN("VIN", this),
		WMI("WMI", this),
		Brand("Brand", this),
		Model("Model", this),
		Year("Year", this),
		AcrissCode("AcrissCode", this),
		BodyType("BodyType", this),
		DateVehicleFirstRegistered("DateVehicleFirstRegistered", this),
		MeetsEmissionStandard("MeetsEmissionStandard", this),
		ProductionDate("ProductionDate", this),
		PurchaseDate("PurchaseDate", this),
		VehicleModelDate("VehicleModelDate", this),
		VehicleConfiguration("VehicleConfiguration", this),
		VehicleSeatingCapacity("VehicleSeatingCapacity", this),
		VehicleSpecialUsage("VehicleSpecialUsage", this),
		VehicleInteriorColor("VehicleInteriorColor", this),
		VehicleInteriorType("VehicleInteriorType", this),
		KnownVehicleDamages("KnownVehicleDamages", this)
    {}

    /**
    * VIN: attribute (string)
    * 17-character Vehicle Identification Number (VIN) as defined by ISO 3779.
    *
    **/
    DataPointString VIN;

    /**
    * WMI: attribute (string)
    * 3-character World Manufacturer Identification (WMI) as defined by ISO 3780.
    *
    **/
    DataPointString WMI;

    /**
    * Brand: attribute (string)
    * Vehicle brand or manufacturer.
    *
    **/
    DataPointString Brand;

    /**
    * Model: attribute (string)
    * Vehicle model.
    *
    **/
    DataPointString Model;

    /**
    * Year: attribute (uint16)
    * Model year of the vehicle.
    *
    **/
    DataPointUint32 Year;

    /**
    * AcrissCode: attribute (string)
    * The ACRISS Car Classification Code is a code used by many car rental companies.
    *
    **/
    DataPointString AcrissCode;

    /**
    * BodyType: attribute (string)
    * Indicates the design and body style of the vehicle (e.g. station wagon, hatchback, etc.).
    *
    **/
    DataPointString BodyType;

    /**
    * DateVehicleFirstRegistered: attribute (string)
    * The date in ISO 8601 format of the first registration of the vehicle with the respective public authorities.
    *
    **/
    DataPointString DateVehicleFirstRegistered;

    /**
    * MeetsEmissionStandard: attribute (string)
    * Indicates that the vehicle meets the respective emission standard.
    *
    **/
    DataPointString MeetsEmissionStandard;

    /**
    * ProductionDate: attribute (string)
    * The date in ISO 8601 format of production of the item, e.g. vehicle.
    *
    **/
    DataPointString ProductionDate;

    /**
    * PurchaseDate: attribute (string)
    * The date in ISO 8601 format of the item e.g. vehicle was purchased by the current owner.
    *
    **/
    DataPointString PurchaseDate;

    /**
    * VehicleModelDate: attribute (string)
    * The release date in ISO 8601 format of a vehicle model (often used to differentiate versions of the same make and model).
    *
    **/
    DataPointString VehicleModelDate;

    /**
    * VehicleConfiguration: attribute (string)
    * A short text indicating the configuration of the vehicle, e.g. '5dr hatchback ST 2.5 MT 225 hp' or 'limited edition'.
    *
    **/
    DataPointString VehicleConfiguration;

    /**
    * VehicleSeatingCapacity: attribute (uint16)
    * The number of passengers that can be seated in the vehicle, both in terms of the physical space available, and in terms of limitations set by law.
    *
    **/
    DataPointUint32 VehicleSeatingCapacity;

    /**
    * VehicleSpecialUsage: attribute (string)
    * Indicates whether the vehicle has been used for special purposes, like commercial rental, driving school.
    *
    **/
    DataPointString VehicleSpecialUsage;

    /**
    * VehicleInteriorColor: attribute (string)
    * The color or color combination of the interior of the vehicle.
    *
    **/
    DataPointString VehicleInteriorColor;

    /**
    * VehicleInteriorType: attribute (string)
    * The type or material of the interior of the vehicle (e.g. synthetic fabric, leather, wood, etc.).
    *
    **/
    DataPointString VehicleInteriorType;

    /**
    * KnownVehicleDamages: attribute (string)
    * A textual description of known damages, both repaired and unrepaired.
    *
    **/
    DataPointString KnownVehicleDamages;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_VEHICLEIDENTIFICATION_H
