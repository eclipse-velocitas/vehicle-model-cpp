#ifndef VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELPARTICULATEFILTER_H
#define VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELPARTICULATEFILTER_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain::combustionengine {
using ParentClass = Model;

/** DieselParticulateFilter model. */
class DieselParticulateFilter : public ParentClass {
public:

    DieselParticulateFilter(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		InletTemperature("InletTemperature", this),
		OutletTemperature("OutletTemperature", this),
		DeltaPressure("DeltaPressure", this)
    {}

    /**
    * InletTemperature: sensor
    * Inlet temperature of Diesel Particulate Filter.
    *
    * Unit: celsius
    **/
    DataPointFloat InletTemperature;

    /**
    * OutletTemperature: sensor
    * Outlet temperature of Diesel Particulate Filter.
    *
    * Unit: celsius
    **/
    DataPointFloat OutletTemperature;

    /**
    * DeltaPressure: sensor
    * Delta Pressure of Diesel Particulate Filter.
    *
    * Unit: Pa
    **/
    DataPointFloat DeltaPressure;

};
} // namespace velocitas::vehicle::powertrain::combustionengine
#endif // VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_DIESELPARTICULATEFILTER_H
