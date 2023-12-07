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

#ifndef VMDL_VEHICLE_POWERTRAIN_FUELSYSTEM_H
#define VMDL_VEHICLE_POWERTRAIN_FUELSYSTEM_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain {
using ParentClass = Model;

/** FuelSystem model. */
class FuelSystem : public ParentClass {
public:

    FuelSystem(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		SupportedFuelTypes("SupportedFuelTypes", this),
		SupportedFuel("SupportedFuel", this),
		HybridType("HybridType", this),
		TankCapacity("TankCapacity", this),
		Level("Level", this),
		Range("Range", this),
		InstantConsumption("InstantConsumption", this),
		AverageConsumption("AverageConsumption", this),
		ConsumptionSinceStart("ConsumptionSinceStart", this),
		TimeSinceStart("TimeSinceStart", this),
		IsEngineStopStartEnabled("IsEngineStopStartEnabled", this),
		IsFuelLevelLow("IsFuelLevelLow", this)
    {}

    /**
    * SupportedFuelTypes: attribute (string[])
    * High level information of fuel types supported
    *
    * If a vehicle also has an electric drivetrain (e.g. hybrid) that will be obvious from the PowerTrain.Type signal.
    *
    * Allowed values: GASOLINE, DIESEL, E85, LPG, CNG, LNG, H2, OTHER
    **/
    DataPointStringArray SupportedFuelTypes;

    /**
    * SupportedFuel: attribute (string[])
    * Detailed information on fuels supported by the vehicle. Identifiers originating from DIN EN 16942:2021-08, appendix B, with additional suffix for octane (RON) where relevant.
    *
    * RON 95 is sometimes referred to as Super, RON 98 as Super Plus.
    *
    * Allowed values: E5_95, E5_98, E10_95, E10_98, E85, B7, B10, B20, B30, B100, XTL, LPG, CNG, LNG, H2, OTHER
    **/
    DataPointStringArray SupportedFuel;

    /**
    * HybridType: attribute (string)
    * Defines the hybrid type of the vehicle.
    *
    * Allowed values: UNKNOWN, NOT_APPLICABLE, STOP_START, BELT_ISG, CIMG, PHEV
    **/
    DataPointString HybridType;

    /**
    * TankCapacity: attribute (float)
    * Capacity of the fuel tank in liters.
    *
    * Unit: l
    **/
    DataPointFloat TankCapacity;

    /**
    * Level: sensor
    * Level in fuel tank as percent of capacity. 0 = empty. 100 = full.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Level;

    /**
    * Range: sensor
    * Remaining range in meters using only liquid fuel.
    *
    * Unit: m
    **/
    DataPointUint32 Range;

    /**
    * InstantConsumption: sensor
    * Current consumption in liters per 100 km.
    *
    * Value range: [0, ]
    * Unit: l/100km
    **/
    DataPointFloat InstantConsumption;

    /**
    * AverageConsumption: sensor
    * Average consumption in liters per 100 km.
    *
    * Value range: [0, ]
    * Unit: l/100km
    **/
    DataPointFloat AverageConsumption;

    /**
    * ConsumptionSinceStart: sensor
    * Fuel amount in liters consumed since start of current trip.
    *
    * Unit: l
    **/
    DataPointFloat ConsumptionSinceStart;

    /**
    * TimeSinceStart: sensor
    * Time in seconds elapsed since start of current trip.
    *
    * Unit: s
    **/
    DataPointUint32 TimeSinceStart;

    /**
    * IsEngineStopStartEnabled: sensor
    * Indicates whether eco start stop is currently enabled.
    *
    **/
    DataPointBoolean IsEngineStopStartEnabled;

    /**
    * IsFuelLevelLow: sensor
    * Indicates that the fuel level is low (e.g. <50km range).
    *
    **/
    DataPointBoolean IsFuelLevelLow;

};
} // namespace velocitas::vehicle::powertrain
#endif // VMDL_VEHICLE_POWERTRAIN_FUELSYSTEM_H
