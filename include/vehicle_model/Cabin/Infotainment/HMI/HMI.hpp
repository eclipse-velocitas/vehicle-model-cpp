#ifndef VMDL_VEHICLE_CABIN_INFOTAINMENT_HMI_H
#define VMDL_VEHICLE_CABIN_INFOTAINMENT_HMI_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::infotainment {
using ParentClass = Model;

/** HMI model. */
class HMI : public ParentClass {
public:

    HMI(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		CurrentLanguage("CurrentLanguage", this),
		DateFormat("DateFormat", this),
		TimeFormat("TimeFormat", this),
		DistanceUnit("DistanceUnit", this),
		FuelEconomyUnits("FuelEconomyUnits", this),
		EVEconomyUnits("EVEconomyUnits", this),
		TemperatureUnit("TemperatureUnit", this),
		DayNightMode("DayNightMode", this)
    {}

    /**
    * CurrentLanguage: sensor
    * ISO 639-1 standard language code for the current HMI
    *
    **/
    DataPointString CurrentLanguage;

    /**
    * DateFormat: actuator
    * Date format used in the current HMI
    *
    * Allowed values: YYYY_MM_DD, DD_MM_YYYY, MM_DD_YYYY, YY_MM_DD, DD_MM_YY, MM_DD_YY
    **/
    DataPointString DateFormat;

    /**
    * TimeFormat: actuator
    * Time format used in the current HMI
    *
    * Allowed values: HR_12, HR_24
    **/
    DataPointString TimeFormat;

    /**
    * DistanceUnit: actuator
    * Distance unit used in the current HMI
    *
    * Allowed values: MILES, KILOMETERS
    **/
    DataPointString DistanceUnit;

    /**
    * FuelEconomyUnits: actuator
    * Fuel economy unit used in the current HMI
    *
    * Allowed values: MPG_UK, MPG_US, MILES_PER_LITER, KILOMETERS_PER_LITER, LITERS_PER_100_KILOMETERS
    **/
    DataPointString FuelEconomyUnits;

    /**
    * EVEconomyUnits: actuator
    * EV fuel economy unit used in the current HMI
    *
    * Allowed values: MILES_PER_KILOWATT_HOUR, KILOMETERS_PER_KILOWATT_HOUR, KILOWATT_HOURS_PER_100_MILES, KILOWATT_HOURS_PER_100_KILOMETERS, WATT_HOURS_PER_MILE, WATT_HOURS_PER_KILOMETER
    **/
    DataPointString EVEconomyUnits;

    /**
    * TemperatureUnit: actuator
    * Temperature unit used in the current HMI
    *
    * Allowed values: C, F
    **/
    DataPointString TemperatureUnit;

    /**
    * DayNightMode: actuator
    * Current display theme
    *
    * Allowed values: DAY, NIGHT
    **/
    DataPointString DayNightMode;

};
} // namespace velocitas::vehicle::cabin::infotainment
#endif // VMDL_VEHICLE_CABIN_INFOTAINMENT_HMI_H
