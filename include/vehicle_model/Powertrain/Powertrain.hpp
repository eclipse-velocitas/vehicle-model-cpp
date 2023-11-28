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

#ifndef VMDL_VEHICLE_POWERTRAIN_H
#define VMDL_VEHICLE_POWERTRAIN_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Powertrain/CombustionEngine/CombustionEngine.hpp"
#include "vehicle_model/Powertrain/ElectricMotor/ElectricMotor.hpp"
#include "vehicle_model/Powertrain/FuelSystem/FuelSystem.hpp"
#include "vehicle_model/Powertrain/TractionBattery/TractionBattery.hpp"
#include "vehicle_model/Powertrain/Transmission/Transmission.hpp"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Powertrain model. */
class Powertrain : public ParentClass {
public:

    Powertrain(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		AccumulatedBrakingEnergy("AccumulatedBrakingEnergy", this),
		Range("Range", this),
		Type("Type", this),
		CombustionEngine("CombustionEngine", this),
		Transmission("Transmission", this),
		ElectricMotor("ElectricMotor", this),
		TractionBattery("TractionBattery", this),
		FuelSystem("FuelSystem", this)
    {}

    /**
    * AccumulatedBrakingEnergy: sensor
    * The accumulated energy from regenerative braking over lifetime.
    *
    * Unit: kWh
    **/
    DataPointFloat AccumulatedBrakingEnergy;

    /**
    * Range: sensor
    * Remaining range in meters using all energy sources available in the vehicle.
    *
    * Unit: m
    **/
    DataPointUint32 Range;

    /**
    * Type: attribute (string)
    * Defines the powertrain type of the vehicle.
    *
    * For vehicles with a combustion engine (including hybrids) more detailed information on fuels supported can be found in FuelSystem.SupportedFuelTypes and FuelSystem.SupportedFuels.
    *
    * Allowed values: COMBUSTION, HYBRID, ELECTRIC
    **/
    DataPointString Type;

    /**
    * CombustionEngine: branch
    * Engine-specific data, stopping at the bell housing.
    *
    **/
    vehicle::powertrain::CombustionEngine CombustionEngine;

    /**
    * Transmission: branch
    * Transmission-specific data, stopping at the drive shafts.
    *
    **/
    vehicle::powertrain::Transmission Transmission;

    /**
    * ElectricMotor: branch
    * Electric Motor specific data.
    *
    **/
    vehicle::powertrain::ElectricMotor ElectricMotor;

    /**
    * TractionBattery: branch
    * Battery Management data.
    *
    **/
    vehicle::powertrain::TractionBattery TractionBattery;

    /**
    * FuelSystem: branch
    * Fuel system data.
    *
    **/
    vehicle::powertrain::FuelSystem FuelSystem;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_POWERTRAIN_H
