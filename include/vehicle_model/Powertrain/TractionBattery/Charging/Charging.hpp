#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Powertrain/TractionBattery/Charging/ChargeCurrent/ChargeCurrent.hpp"
#include "vehicle_model/Powertrain/TractionBattery/Charging/ChargeVoltage/ChargeVoltage.hpp"
#include "vehicle_model/Powertrain/TractionBattery/Charging/MaximumChargingCurrent/MaximumChargingCurrent.hpp"
#include "vehicle_model/Powertrain/TractionBattery/Charging/Timer/Timer.hpp"

namespace velocitas::vehicle::powertrain::tractionbattery {
using ParentClass = Model;

/** Charging model. */
class Charging : public ParentClass {
public:

    Charging(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		ChargeLimit("ChargeLimit", this),
		MaximumChargingCurrent("MaximumChargingCurrent", this),
		ChargePortFlap("ChargePortFlap", this),
		IsChargingCableConnected("IsChargingCableConnected", this),
		IsChargingCableLocked("IsChargingCableLocked", this),
		ChargePlugType("ChargePlugType", this),
		Mode("Mode", this),
		IsCharging("IsCharging", this),
		IsDischarging("IsDischarging", this),
		StartStopCharging("StartStopCharging", this),
		ChargeCurrent("ChargeCurrent", this),
		ChargeVoltage("ChargeVoltage", this),
		PowerLoss("PowerLoss", this),
		Temperature("Temperature", this),
		ChargeRate("ChargeRate", this),
		TimeToComplete("TimeToComplete", this),
		Timer("Timer", this)
    {}

    /**
    * ChargeLimit: actuator
    * Target charge limit (state of charge) for battery.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 ChargeLimit;

    /**
    * MaximumChargingCurrent: branch
    * Maximum charging current that can be accepted by the system, as measured at the charging inlet.
    *
    **/
    vehicle::powertrain::tractionbattery::charging::MaximumChargingCurrent MaximumChargingCurrent;

    /**
    * ChargePortFlap: actuator
    * Status of the charge port cover, can potentially be controlled manually.
    *
    * Allowed values: OPEN, CLOSED
    **/
    DataPointString ChargePortFlap;

    /**
    * IsChargingCableConnected: sensor
    * Indicates if a charging cable is physically connected to the vehicle or not.
    *
    **/
    DataPointBoolean IsChargingCableConnected;

    /**
    * IsChargingCableLocked: actuator
    * Is charging cable locked to prevent removal.
    *
    * Locking of charging cable can be used to prevent unintentional removing during charging.
    *
    **/
    DataPointBoolean IsChargingCableLocked;

    /**
    * ChargePlugType: attribute (string[])
    * Type of charge plug (charging inlet) available on the vehicle. IEC types refer to IEC 62196,  GBT refers to  GB/T 20234.
    *
    * A vehicle may have multiple charging inlets. IEC_TYPE_1_AC refers to Type 1 as defined in IEC 62196-2. Also known as Yazaki or J1772 connector. IEC_TYPE_2_AC refers to Type 2 as defined in IEC 62196-2. Also known as Mennekes connector. IEC_TYPE_3_AC refers to Type 3 as defined in IEC 62196-2. Also known as Scame connector. IEC_TYPE_4_DC refers to AA configuration as defined in IEC 62196-3. Also known as Type 4 or CHAdeMO connector. IEC_TYPE_1_CCS_DC refers to EE Configuration as defined in IEC 62196-3. Also known as CCS1 or Combo1 connector. IEC_TYPE_2_CCS_DC refers to FF Configuration as defined in IEC 62196-3. Also known as CCS2 or Combo2 connector. TESLA_ROADSTER, TESLA_HPWC (High Power Wall Connector) and TESLA_SUPERCHARGER refer to non-standardized charging inlets/methods used by Tesla. GBT_AC refers to connector specified in GB/T 20234.2. GBT_DC refers to connector specified in GB/T 20234.3. Also specified as BB Configuration in IEC 62196-3. OTHER shall be used if the vehicle has a charging connector, but not one of the connectors listed above. For additional information see https://en.wikipedia.org/wiki/IEC_62196.
    *
    * Allowed values: IEC_TYPE_1_AC, IEC_TYPE_2_AC, IEC_TYPE_3_AC, IEC_TYPE_4_DC, IEC_TYPE_1_CCS_DC, IEC_TYPE_2_CCS_DC, TESLA_ROADSTER, TESLA_HPWC, TESLA_SUPERCHARGER, GBT_AC, GBT_DC, OTHER
    **/
    DataPointStringArray ChargePlugType;

    /**
    * Mode: actuator
    * Control of the charge process. MANUAL means manually initiated (plug-in event, companion app, etc). TIMER means timer-based. GRID means grid-controlled (eg ISO 15118). PROFILE means controlled by profile download to vehicle.
    *
    * The mechanism to provide a profile to the vehicle is currently not covered by VSS.
    *
    * Allowed values: MANUAL, TIMER, GRID, PROFILE
    **/
    DataPointString Mode;

    /**
    * IsCharging: sensor
    * True if charging is ongoing. Charging is considered to be ongoing if energy is flowing from charger to vehicle.
    *
    **/
    DataPointBoolean IsCharging;

    /**
    * IsDischarging: sensor
    * True if discharging (vehicle to grid) is ongoing. Discharging is considered to be ongoing if energy is flowing from vehicle to charger/grid.
    *
    **/
    DataPointBoolean IsDischarging;

    /**
    * StartStopCharging: actuator
    * Start or stop the charging process.
    *
    * Allowed values: START, STOP
    **/
    DataPointString StartStopCharging;

    /**
    * ChargeCurrent: branch
    * Current charging current.
    *
    **/
    vehicle::powertrain::tractionbattery::charging::ChargeCurrent ChargeCurrent;

    /**
    * ChargeVoltage: branch
    * Current charging voltage, as measured at the charging inlet.
    *
    **/
    vehicle::powertrain::tractionbattery::charging::ChargeVoltage ChargeVoltage;

    /**
    * PowerLoss: sensor
    * Electrical energy lost by power dissipation to heat inside the AC/DC converter.
    *
    * Unit: W
    **/
    DataPointFloat PowerLoss;

    /**
    * Temperature: sensor
    * Current temperature of AC/DC converter converting grid voltage to battery voltage.
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature;

    /**
    * ChargeRate: sensor
    * Current charging rate, as in kilometers of range added per hour.
    *
    * Unit: km/h
    **/
    DataPointFloat ChargeRate;

    /**
    * TimeToComplete: sensor
    * The time needed for the current charging process to reach Charging.ChargeLimit. 0 if charging is complete or no charging process is active or planned.
    *
    * Shall consider time set by Charging.Timer.Time. E.g. if charging shall start in 3 hours and 2 hours of charging is needed, then Charging.TimeToComplete shall report 5 hours.
    *
    * Unit: s
    **/
    DataPointUint32 TimeToComplete;

    /**
    * Timer: branch
    * Properties related to timing of battery charging sessions.
    *
    **/
    vehicle::powertrain::tractionbattery::charging::Timer Timer;

};
} // namespace velocitas::vehicle::powertrain::tractionbattery
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_H
