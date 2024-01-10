/**
 * Copyright (c) 2023-2024 Contributors to the Eclipse Foundation
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VMDL_VEHICLE_OBD_H
#define VMDL_VEHICLE_OBD_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/OBD/Catalyst/Catalyst.hpp"
#include "vehicle_model/OBD/DriveCycleStatus/DriveCycleStatus.hpp"
#include "vehicle_model/OBD/O2/O2.hpp"
#include "vehicle_model/OBD/O2WR/O2WR.hpp"
#include "vehicle_model/OBD/Status/Status.hpp"

#include <stdexcept>

namespace velocitas::vehicle {
using ParentClass = Model;

/** OBD model. */
class OBD : public ParentClass {
public:
    class O2Collection : public ParentClass {
    public:

        O2Collection(ParentClass* parent):
            ParentClass("O2", parent),
            Sensor1("Sensor1", this),
            Sensor2("Sensor2", this),
            Sensor3("Sensor3", this),
            Sensor4("Sensor4", this),
            Sensor5("Sensor5", this),
            Sensor6("Sensor6", this),
            Sensor7("Sensor7", this),
            Sensor8("Sensor8", this)
        {
        }

        vehicle::obd::O2& Sensor(int index) {
            if (index == 1) {
                return Sensor1;
            }
            if (index == 2) {
                return Sensor2;
            }
            if (index == 3) {
                return Sensor3;
            }
            if (index == 4) {
                return Sensor4;
            }
            if (index == 5) {
                return Sensor5;
            }
            if (index == 6) {
                return Sensor6;
            }
            if (index == 7) {
                return Sensor7;
            }
            if (index == 8) {
                return Sensor8;
            }
            throw std::runtime_error("Given value is outside of allowed range [1;8]!");
        }

        vehicle::obd::O2 Sensor1;
        vehicle::obd::O2 Sensor2;
        vehicle::obd::O2 Sensor3;
        vehicle::obd::O2 Sensor4;
        vehicle::obd::O2 Sensor5;
        vehicle::obd::O2 Sensor6;
        vehicle::obd::O2 Sensor7;
        vehicle::obd::O2 Sensor8;
    };


    class O2WRCollection : public ParentClass {
    public:

        O2WRCollection(ParentClass* parent):
            ParentClass("O2WR", parent),
            Sensor1("Sensor1", this),
            Sensor2("Sensor2", this),
            Sensor3("Sensor3", this),
            Sensor4("Sensor4", this),
            Sensor5("Sensor5", this),
            Sensor6("Sensor6", this),
            Sensor7("Sensor7", this),
            Sensor8("Sensor8", this)
        {
        }

        vehicle::obd::O2WR& Sensor(int index) {
            if (index == 1) {
                return Sensor1;
            }
            if (index == 2) {
                return Sensor2;
            }
            if (index == 3) {
                return Sensor3;
            }
            if (index == 4) {
                return Sensor4;
            }
            if (index == 5) {
                return Sensor5;
            }
            if (index == 6) {
                return Sensor6;
            }
            if (index == 7) {
                return Sensor7;
            }
            if (index == 8) {
                return Sensor8;
            }
            throw std::runtime_error("Given value is outside of allowed range [1;8]!");
        }

        vehicle::obd::O2WR Sensor1;
        vehicle::obd::O2WR Sensor2;
        vehicle::obd::O2WR Sensor3;
        vehicle::obd::O2WR Sensor4;
        vehicle::obd::O2WR Sensor5;
        vehicle::obd::O2WR Sensor6;
        vehicle::obd::O2WR Sensor7;
        vehicle::obd::O2WR Sensor8;
    };

    OBD(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		PidsA("PidsA", this),
		Status("Status", this),
		DTCList("DTCList", this),
		FreezeDTC("FreezeDTC", this),
		FuelStatus("FuelStatus", this),
		EngineLoad("EngineLoad", this),
		CoolantTemperature("CoolantTemperature", this),
		ShortTermFuelTrim1("ShortTermFuelTrim1", this),
		LongTermFuelTrim1("LongTermFuelTrim1", this),
		ShortTermFuelTrim2("ShortTermFuelTrim2", this),
		LongTermFuelTrim2("LongTermFuelTrim2", this),
		FuelPressure("FuelPressure", this),
		MAP("MAP", this),
		EngineSpeed("EngineSpeed", this),
		Speed("Speed", this),
		TimingAdvance("TimingAdvance", this),
		IntakeTemp("IntakeTemp", this),
		MAF("MAF", this),
		ThrottlePosition("ThrottlePosition", this),
		AirStatus("AirStatus", this),
		OxygenSensorsIn2Banks("OxygenSensorsIn2Banks", this),
		O2(this),
		OBDStandards("OBDStandards", this),
		OxygenSensorsIn4Banks("OxygenSensorsIn4Banks", this),
		IsPTOActive("IsPTOActive", this),
		RunTime("RunTime", this),
		PidsB("PidsB", this),
		DistanceWithMIL("DistanceWithMIL", this),
		FuelRailPressureVac("FuelRailPressureVac", this),
		FuelRailPressureDirect("FuelRailPressureDirect", this),
		O2WR(this),
		CommandedEGR("CommandedEGR", this),
		EGRError("EGRError", this),
		CommandedEVAP("CommandedEVAP", this),
		FuelLevel("FuelLevel", this),
		WarmupsSinceDTCClear("WarmupsSinceDTCClear", this),
		DistanceSinceDTCClear("DistanceSinceDTCClear", this),
		EVAPVaporPressure("EVAPVaporPressure", this),
		BarometricPressure("BarometricPressure", this),
		Catalyst("Catalyst", this),
		PidsC("PidsC", this),
		DriveCycleStatus("DriveCycleStatus", this),
		ControlModuleVoltage("ControlModuleVoltage", this),
		AbsoluteLoad("AbsoluteLoad", this),
		CommandedEquivalenceRatio("CommandedEquivalenceRatio", this),
		RelativeThrottlePosition("RelativeThrottlePosition", this),
		AmbientAirTemperature("AmbientAirTemperature", this),
		ThrottlePositionB("ThrottlePositionB", this),
		ThrottlePositionC("ThrottlePositionC", this),
		AcceleratorPositionD("AcceleratorPositionD", this),
		AcceleratorPositionE("AcceleratorPositionE", this),
		AcceleratorPositionF("AcceleratorPositionF", this),
		ThrottleActuator("ThrottleActuator", this),
		RunTimeMIL("RunTimeMIL", this),
		TimeSinceDTCCleared("TimeSinceDTCCleared", this),
		MaxMAF("MaxMAF", this),
		FuelType("FuelType", this),
		EthanolPercent("EthanolPercent", this),
		EVAPVaporPressureAbsolute("EVAPVaporPressureAbsolute", this),
		EVAPVaporPressureAlternate("EVAPVaporPressureAlternate", this),
		ShortTermO2Trim1("ShortTermO2Trim1", this),
		ShortTermO2Trim3("ShortTermO2Trim3", this),
		LongTermO2Trim1("LongTermO2Trim1", this),
		LongTermO2Trim3("LongTermO2Trim3", this),
		ShortTermO2Trim2("ShortTermO2Trim2", this),
		ShortTermO2Trim4("ShortTermO2Trim4", this),
		LongTermO2Trim2("LongTermO2Trim2", this),
		LongTermO2Trim4("LongTermO2Trim4", this),
		FuelRailPressureAbsolute("FuelRailPressureAbsolute", this),
		RelativeAcceleratorPosition("RelativeAcceleratorPosition", this),
		HybridBatteryRemaining("HybridBatteryRemaining", this),
		OilTemperature("OilTemperature", this),
		FuelInjectionTiming("FuelInjectionTiming", this),
		FuelRate("FuelRate", this)
    {}

    /**
    * PidsA: sensor
    * PID 00 - Bit array of the supported pids 01 to 20
    *
    **/
    DataPointUint32 PidsA;

    /**
    * Status: branch
    * PID 01 - OBD status
    *
    **/
    vehicle::obd::Status Status;

    /**
    * DTCList: sensor
    * List of currently active DTCs formatted according OBD II (SAE-J2012DA_201812) standard ([P|C|B|U]XXXXX )
    *
    **/
    DataPointStringArray DTCList;

    /**
    * FreezeDTC: sensor
    * PID 02 - DTC that triggered the freeze frame
    *
    **/
    DataPointString FreezeDTC;

    /**
    * FuelStatus: sensor
    * PID 03 - Fuel status
    *
    **/
    DataPointString FuelStatus;

    /**
    * EngineLoad: sensor
    * PID 04 - Engine load in percent - 0 = no load, 100 = full load
    *
    * Unit: percent
    **/
    DataPointFloat EngineLoad;

    /**
    * CoolantTemperature: sensor
    * PID 05 - Coolant temperature
    *
    * Unit: celsius
    **/
    DataPointFloat CoolantTemperature;

    /**
    * ShortTermFuelTrim1: sensor
    * PID 06 - Short Term (immediate) Fuel Trim - Bank 1 - negative percent leaner, positive percent richer
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermFuelTrim1;

    /**
    * LongTermFuelTrim1: sensor
    * PID 07 - Long Term (learned) Fuel Trim - Bank 1 - negative percent leaner, positive percent richer
    *
    * Unit: percent
    **/
    DataPointFloat LongTermFuelTrim1;

    /**
    * ShortTermFuelTrim2: sensor
    * PID 08 - Short Term (immediate) Fuel Trim - Bank 2 - negative percent leaner, positive percent richer
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermFuelTrim2;

    /**
    * LongTermFuelTrim2: sensor
    * PID 09 - Long Term (learned) Fuel Trim - Bank 2 - negative percent leaner, positive percent richer
    *
    * Unit: percent
    **/
    DataPointFloat LongTermFuelTrim2;

    /**
    * FuelPressure: sensor
    * PID 0A - Fuel pressure
    *
    * Unit: kPa
    **/
    DataPointFloat FuelPressure;

    /**
    * MAP: sensor
    * PID 0B - Intake manifold pressure
    *
    * Unit: kPa
    **/
    DataPointFloat MAP;

    /**
    * EngineSpeed: sensor
    * PID 0C - Engine speed measured as rotations per minute
    *
    * Unit: rpm
    **/
    DataPointFloat EngineSpeed;

    /**
    * Speed: sensor
    * PID 0D - Vehicle speed
    *
    * Unit: km/h
    **/
    DataPointFloat Speed;

    /**
    * TimingAdvance: sensor
    * PID 0E - Time advance
    *
    * Unit: degrees
    **/
    DataPointFloat TimingAdvance;

    /**
    * IntakeTemp: sensor
    * PID 0F - Intake temperature
    *
    * Unit: celsius
    **/
    DataPointFloat IntakeTemp;

    /**
    * MAF: sensor
    * PID 10 - Grams of air drawn into engine per second
    *
    * Unit: g/s
    **/
    DataPointFloat MAF;

    /**
    * ThrottlePosition: sensor
    * PID 11 - Throttle position - 0 = closed throttle, 100 = open throttle
    *
    * Unit: percent
    **/
    DataPointFloat ThrottlePosition;

    /**
    * AirStatus: sensor
    * PID 12 - Secondary air status
    *
    **/
    DataPointString AirStatus;

    /**
    * OxygenSensorsIn2Banks: sensor
    * PID 13 - Presence of oxygen sensors in 2 banks. [A0..A3] == Bank 1, Sensors 1-4. [A4..A7] == Bank 2, Sensors 1-4
    *
    **/
    DataPointUint32 OxygenSensorsIn2Banks;

    /**
    * O2: branch
    * Oxygen sensors (PID 14 - PID 1B)
    *
    **/
    O2Collection O2;

    /**
    * OBDStandards: attribute (uint8)
    * PID 1C - OBD standards this vehicle conforms to
    *
    **/
    DataPointUint32 OBDStandards;

    /**
    * OxygenSensorsIn4Banks: sensor
    * PID 1D - Presence of oxygen sensors in 4 banks. Similar to PID 13, but [A0..A7] == [B1S1, B1S2, B2S1, B2S2, B3S1, B3S2, B4S1, B4S2]
    *
    **/
    DataPointUint32 OxygenSensorsIn4Banks;

    /**
    * IsPTOActive: sensor
    * PID 1E - Auxiliary input status (power take off)
    *
    **/
    DataPointBoolean IsPTOActive;

    /**
    * RunTime: sensor
    * PID 1F - Engine run time
    *
    * Unit: s
    **/
    DataPointFloat RunTime;

    /**
    * PidsB: sensor
    * PID 20 - Bit array of the supported pids 21 to 40
    *
    **/
    DataPointUint32 PidsB;

    /**
    * DistanceWithMIL: sensor
    * PID 21 - Distance traveled with MIL on
    *
    * Unit: km
    **/
    DataPointFloat DistanceWithMIL;

    /**
    * FuelRailPressureVac: sensor
    * PID 22 - Fuel rail pressure relative to vacuum
    *
    * Unit: kPa
    **/
    DataPointFloat FuelRailPressureVac;

    /**
    * FuelRailPressureDirect: sensor
    * PID 23 - Fuel rail pressure direct inject
    *
    * Unit: kPa
    **/
    DataPointFloat FuelRailPressureDirect;

    /**
    * O2WR: branch
    * Wide range/band oxygen sensors (PID 24 - 2B and PID 34 - 3B)
    *
    **/
    O2WRCollection O2WR;

    /**
    * CommandedEGR: sensor
    * PID 2C - Commanded exhaust gas recirculation (EGR)
    *
    * Unit: percent
    **/
    DataPointFloat CommandedEGR;

    /**
    * EGRError: sensor
    * PID 2D - Exhaust gas recirculation (EGR) error
    *
    * Unit: percent
    **/
    DataPointFloat EGRError;

    /**
    * CommandedEVAP: sensor
    * PID 2E - Commanded evaporative purge (EVAP) valve
    *
    * Unit: percent
    **/
    DataPointFloat CommandedEVAP;

    /**
    * FuelLevel: sensor
    * PID 2F - Fuel level in the fuel tank
    *
    * Unit: percent
    **/
    DataPointFloat FuelLevel;

    /**
    * WarmupsSinceDTCClear: sensor
    * PID 30 - Number of warm-ups since codes cleared
    *
    **/
    DataPointUint32 WarmupsSinceDTCClear;

    /**
    * DistanceSinceDTCClear: sensor
    * PID 31 - Distance traveled since codes cleared
    *
    * Unit: km
    **/
    DataPointFloat DistanceSinceDTCClear;

    /**
    * EVAPVaporPressure: sensor
    * PID 32 - Evaporative purge (EVAP) system pressure
    *
    * Unit: Pa
    **/
    DataPointFloat EVAPVaporPressure;

    /**
    * BarometricPressure: sensor
    * PID 33 - Barometric pressure
    *
    * Unit: kPa
    **/
    DataPointFloat BarometricPressure;

    /**
    * Catalyst: branch
    * Catalyst signals
    *
    **/
    vehicle::obd::Catalyst Catalyst;

    /**
    * PidsC: sensor
    * PID 40 - Bit array of the supported pids 41 to 60
    *
    **/
    DataPointUint32 PidsC;

    /**
    * DriveCycleStatus: branch
    * PID 41 - OBD status for the current drive cycle
    *
    **/
    vehicle::obd::DriveCycleStatus DriveCycleStatus;

    /**
    * ControlModuleVoltage: sensor
    * PID 42 - Control module voltage
    *
    * Unit: V
    **/
    DataPointFloat ControlModuleVoltage;

    /**
    * AbsoluteLoad: sensor
    * PID 43 - Absolute load value
    *
    * Unit: percent
    **/
    DataPointFloat AbsoluteLoad;

    /**
    * CommandedEquivalenceRatio: sensor
    * PID 44 - Commanded equivalence ratio
    *
    * Unit: ratio
    **/
    DataPointFloat CommandedEquivalenceRatio;

    /**
    * RelativeThrottlePosition: sensor
    * PID 45 - Relative throttle position
    *
    * Unit: percent
    **/
    DataPointFloat RelativeThrottlePosition;

    /**
    * AmbientAirTemperature: sensor
    * PID 46 - Ambient air temperature
    *
    * Unit: celsius
    **/
    DataPointFloat AmbientAirTemperature;

    /**
    * ThrottlePositionB: sensor
    * PID 47 - Absolute throttle position B
    *
    * Unit: percent
    **/
    DataPointFloat ThrottlePositionB;

    /**
    * ThrottlePositionC: sensor
    * PID 48 - Absolute throttle position C
    *
    * Unit: percent
    **/
    DataPointFloat ThrottlePositionC;

    /**
    * AcceleratorPositionD: sensor
    * PID 49 - Accelerator pedal position D
    *
    * Unit: percent
    **/
    DataPointFloat AcceleratorPositionD;

    /**
    * AcceleratorPositionE: sensor
    * PID 4A - Accelerator pedal position E
    *
    * Unit: percent
    **/
    DataPointFloat AcceleratorPositionE;

    /**
    * AcceleratorPositionF: sensor
    * PID 4B - Accelerator pedal position F
    *
    * Unit: percent
    **/
    DataPointFloat AcceleratorPositionF;

    /**
    * ThrottleActuator: sensor
    * PID 4C - Commanded throttle actuator
    *
    * Unit: percent
    **/
    DataPointFloat ThrottleActuator;

    /**
    * RunTimeMIL: sensor
    * PID 4D - Run time with MIL on
    *
    * Unit: min
    **/
    DataPointFloat RunTimeMIL;

    /**
    * TimeSinceDTCCleared: sensor
    * PID 4E - Time since trouble codes cleared
    *
    * Unit: min
    **/
    DataPointFloat TimeSinceDTCCleared;

    /**
    * MaxMAF: sensor
    * PID 50 - Maximum flow for mass air flow sensor
    *
    * Unit: g/s
    **/
    DataPointFloat MaxMAF;

    /**
    * FuelType: sensor
    * PID 51 - Fuel type
    *
    **/
    DataPointString FuelType;

    /**
    * EthanolPercent: sensor
    * PID 52 - Percentage of ethanol in the fuel
    *
    * Unit: percent
    **/
    DataPointFloat EthanolPercent;

    /**
    * EVAPVaporPressureAbsolute: sensor
    * PID 53 - Absolute evaporative purge (EVAP) system pressure
    *
    * Unit: kPa
    **/
    DataPointFloat EVAPVaporPressureAbsolute;

    /**
    * EVAPVaporPressureAlternate: sensor
    * PID 54 - Alternate evaporative purge (EVAP) system pressure
    *
    * Unit: Pa
    **/
    DataPointFloat EVAPVaporPressureAlternate;

    /**
    * ShortTermO2Trim1: sensor
    * PID 55 (byte A) - Short term secondary O2 trim - Bank 1
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermO2Trim1;

    /**
    * ShortTermO2Trim3: sensor
    * PID 55 (byte B) - Short term secondary O2 trim - Bank 3
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermO2Trim3;

    /**
    * LongTermO2Trim1: sensor
    * PID 56 (byte A) - Long term secondary O2 trim - Bank 1
    *
    * Unit: percent
    **/
    DataPointFloat LongTermO2Trim1;

    /**
    * LongTermO2Trim3: sensor
    * PID 56 (byte B) - Long term secondary O2 trim - Bank 3
    *
    * Unit: percent
    **/
    DataPointFloat LongTermO2Trim3;

    /**
    * ShortTermO2Trim2: sensor
    * PID 57 (byte A) - Short term secondary O2 trim - Bank 2
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermO2Trim2;

    /**
    * ShortTermO2Trim4: sensor
    * PID 57 (byte B) - Short term secondary O2 trim - Bank 4
    *
    * Unit: percent
    **/
    DataPointFloat ShortTermO2Trim4;

    /**
    * LongTermO2Trim2: sensor
    * PID 58 (byte A) - Long term secondary O2 trim - Bank 2
    *
    * Unit: percent
    **/
    DataPointFloat LongTermO2Trim2;

    /**
    * LongTermO2Trim4: sensor
    * PID 58 (byte B) - Long term secondary O2 trim - Bank 4
    *
    * Unit: percent
    **/
    DataPointFloat LongTermO2Trim4;

    /**
    * FuelRailPressureAbsolute: sensor
    * PID 59 - Absolute fuel rail pressure
    *
    * Unit: kPa
    **/
    DataPointFloat FuelRailPressureAbsolute;

    /**
    * RelativeAcceleratorPosition: sensor
    * PID 5A - Relative accelerator pedal position
    *
    * Unit: percent
    **/
    DataPointFloat RelativeAcceleratorPosition;

    /**
    * HybridBatteryRemaining: sensor
    * PID 5B - Remaining life of hybrid battery
    *
    * Unit: percent
    **/
    DataPointFloat HybridBatteryRemaining;

    /**
    * OilTemperature: sensor
    * PID 5C - Engine oil temperature
    *
    * Unit: celsius
    **/
    DataPointFloat OilTemperature;

    /**
    * FuelInjectionTiming: sensor
    * PID 5D - Fuel injection timing
    *
    * Unit: degrees
    **/
    DataPointFloat FuelInjectionTiming;

    /**
    * FuelRate: sensor
    * PID 5E - Engine fuel rate
    *
    * Unit: l/h
    **/
    DataPointFloat FuelRate;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_OBD_H
