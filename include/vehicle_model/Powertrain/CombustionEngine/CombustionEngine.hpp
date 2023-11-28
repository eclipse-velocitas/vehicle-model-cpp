/**
 * Copyright (c) 2023 Contributors to the Eclipse Foundation
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

#ifndef VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_H
#define VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Powertrain/CombustionEngine/DieselExhaustFluid/DieselExhaustFluid.hpp"
#include "vehicle_model/Powertrain/CombustionEngine/DieselParticulateFilter/DieselParticulateFilter.hpp"

namespace velocitas::vehicle::powertrain {
using ParentClass = Model;

/** CombustionEngine model. */
class CombustionEngine : public ParentClass {
public:

    CombustionEngine(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		EngineCode("EngineCode", this),
		Displacement("Displacement", this),
		StrokeLength("StrokeLength", this),
		Bore("Bore", this),
		Configuration("Configuration", this),
		NumberOfCylinders("NumberOfCylinders", this),
		NumberOfValvesPerCylinder("NumberOfValvesPerCylinder", this),
		CompressionRatio("CompressionRatio", this),
		EngineOilCapacity("EngineOilCapacity", this),
		EngineCoolantCapacity("EngineCoolantCapacity", this),
		MaxPower("MaxPower", this),
		MaxTorque("MaxTorque", this),
		AspirationType("AspirationType", this),
		EngineOilLevel("EngineOilLevel", this),
		OilLifeRemaining("OilLifeRemaining", this),
		IsRunning("IsRunning", this),
		Speed("Speed", this),
		EngineHours("EngineHours", this),
		IdleHours("IdleHours", this),
		ECT("ECT", this),
		EOT("EOT", this),
		MAP("MAP", this),
		MAF("MAF", this),
		TPS("TPS", this),
		EOP("EOP", this),
		Power("Power", this),
		Torque("Torque", this),
		DieselExhaustFluid("DieselExhaustFluid", this),
		DieselParticulateFilter("DieselParticulateFilter", this)
    {}

    /**
    * EngineCode: attribute (string)
    * Engine code designation, as specified by vehicle manufacturer.
    *
    * For hybrid vehicles the engine code may refer to the combination of combustion and electric engine.
    *
    **/
    DataPointString EngineCode;

    /**
    * Displacement: attribute (uint16)
    * Displacement in cubic centimetres.
    *
    * Unit: cm^3
    **/
    DataPointUint32 Displacement;

    /**
    * StrokeLength: attribute (float)
    * Stroke length in millimetres.
    *
    * Unit: mm
    **/
    DataPointFloat StrokeLength;

    /**
    * Bore: attribute (float)
    * Bore in millimetres.
    *
    * Unit: mm
    **/
    DataPointFloat Bore;

    /**
    * Configuration: attribute (string)
    * Engine configuration.
    *
    * Allowed values: UNKNOWN, STRAIGHT, V, BOXER, W, ROTARY, RADIAL, SQUARE, H, U, OPPOSED, X
    **/
    DataPointString Configuration;

    /**
    * NumberOfCylinders: attribute (uint16)
    * Number of cylinders.
    *
    **/
    DataPointUint32 NumberOfCylinders;

    /**
    * NumberOfValvesPerCylinder: attribute (uint16)
    * Number of valves per cylinder.
    *
    **/
    DataPointUint32 NumberOfValvesPerCylinder;

    /**
    * CompressionRatio: attribute (string)
    * Engine compression ratio, specified in the format 'X:1', e.g. '9.2:1'.
    *
    **/
    DataPointString CompressionRatio;

    /**
    * EngineOilCapacity: attribute (float)
    * Engine oil capacity in liters.
    *
    * Unit: l
    **/
    DataPointFloat EngineOilCapacity;

    /**
    * EngineCoolantCapacity: attribute (float)
    * Engine coolant capacity in liters.
    *
    * Unit: l
    **/
    DataPointFloat EngineCoolantCapacity;

    /**
    * MaxPower: attribute (uint16)
    * Peak power, in kilowatts, that engine can generate.
    *
    * Unit: kW
    **/
    DataPointUint32 MaxPower;

    /**
    * MaxTorque: attribute (uint16)
    * Peak torque, in newton meter, that the engine can generate.
    *
    * Unit: Nm
    **/
    DataPointUint32 MaxTorque;

    /**
    * AspirationType: attribute (string)
    * Type of aspiration (natural, turbocharger, supercharger etc).
    *
    * Allowed values: UNKNOWN, NATURAL, SUPERCHARGER, TURBOCHARGER
    **/
    DataPointString AspirationType;

    /**
    * EngineOilLevel: sensor
    * Engine oil level.
    *
    * Allowed values: CRITICALLY_LOW, LOW, NORMAL, HIGH, CRITICALLY_HIGH
    **/
    DataPointString EngineOilLevel;

    /**
    * OilLifeRemaining: sensor
    * Remaining engine oil life in seconds. Negative values can be used to indicate that lifetime has been exceeded.
    *
    * In addition to this a signal a vehicle can report remaining time to service (including e.g. oil change) by Vehicle.Service.TimeToService.
    *
    * Unit: s
    **/
    DataPointInt32 OilLifeRemaining;

    /**
    * IsRunning: sensor
    * Engine Running. True if engine is rotating (Speed > 0).
    *
    **/
    DataPointBoolean IsRunning;

    /**
    * Speed: sensor
    * Engine speed measured as rotations per minute.
    *
    * Unit: rpm
    **/
    DataPointUint32 Speed;

    /**
    * EngineHours: sensor
    * Accumulated time during engine lifetime with 'engine speed (rpm) > 0'.
    *
    * Unit: h
    **/
    DataPointFloat EngineHours;

    /**
    * IdleHours: sensor
    * Accumulated idling time during engine lifetime. Definition of idling is not standardized.
    *
    * Vehicles may calculate accumulated idle time for an engine. It might be based on engine speed (rpm) below a certain limit or any other mechanism.
    *
    * Unit: h
    **/
    DataPointFloat IdleHours;

    /**
    * ECT: sensor
    * Engine coolant temperature.
    *
    * Unit: celsius
    **/
    DataPointInt32 ECT;

    /**
    * EOT: sensor
    * Engine oil temperature.
    *
    * Unit: celsius
    **/
    DataPointInt32 EOT;

    /**
    * MAP: sensor
    * Manifold absolute pressure possibly boosted using forced induction.
    *
    * Unit: kPa
    **/
    DataPointUint32 MAP;

    /**
    * MAF: sensor
    * Grams of air drawn into engine per second.
    *
    * Unit: g/s
    **/
    DataPointUint32 MAF;

    /**
    * TPS: sensor
    * Current throttle position.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 TPS;

    /**
    * EOP: sensor
    * Engine oil pressure.
    *
    * Unit: kPa
    **/
    DataPointUint32 EOP;

    /**
    * Power: sensor
    * Current engine power output. Shall be reported as 0 during engine breaking.
    *
    * Unit: kW
    **/
    DataPointUint32 Power;

    /**
    * Torque: sensor
    * Current engine torque. Shall be reported as 0 during engine breaking.
    *
    * During engine breaking the engine delivers a negative torque to the transmission. This negative torque shall be ignored, instead 0 shall be reported.
    *
    * Unit: Nm
    **/
    DataPointUint32 Torque;

    /**
    * DieselExhaustFluid: branch
    * Signals related to Diesel Exhaust Fluid (DEF). DEF is called AUS32 in ISO 22241.
    *
    * In retail and marketing other names are typically used for the fluid.
    *
    **/
    vehicle::powertrain::combustionengine::DieselExhaustFluid DieselExhaustFluid;

    /**
    * DieselParticulateFilter: branch
    * Diesel Particulate Filter signals.
    *
    **/
    vehicle::powertrain::combustionengine::DieselParticulateFilter DieselParticulateFilter;

};
} // namespace velocitas::vehicle::powertrain
#endif // VMDL_VEHICLE_POWERTRAIN_COMBUSTIONENGINE_H
