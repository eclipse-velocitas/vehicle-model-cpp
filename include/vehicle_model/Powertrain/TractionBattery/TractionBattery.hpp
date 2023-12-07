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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_H
#define VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Powertrain/TractionBattery/Charging/Charging.hpp"
#include "vehicle_model/Powertrain/TractionBattery/DCDC/DCDC.hpp"
#include "vehicle_model/Powertrain/TractionBattery/StateOfCharge/StateOfCharge.hpp"
#include "vehicle_model/Powertrain/TractionBattery/Temperature/Temperature.hpp"

namespace velocitas::vehicle::powertrain {
using ParentClass = Model;

/** TractionBattery model. */
class TractionBattery : public ParentClass {
public:

    TractionBattery(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Id("Id", this),
		ProductionDate("ProductionDate", this),
		IsPowerConnected("IsPowerConnected", this),
		IsGroundConnected("IsGroundConnected", this),
		Temperature("Temperature", this),
		GrossCapacity("GrossCapacity", this),
		NetCapacity("NetCapacity", this),
		StateOfHealth("StateOfHealth", this),
		StateOfCharge("StateOfCharge", this),
		NominalVoltage("NominalVoltage", this),
		MaxVoltage("MaxVoltage", this),
		CurrentVoltage("CurrentVoltage", this),
		CurrentCurrent("CurrentCurrent", this),
		CurrentPower("CurrentPower", this),
		AccumulatedChargedEnergy("AccumulatedChargedEnergy", this),
		AccumulatedConsumedEnergy("AccumulatedConsumedEnergy", this),
		AccumulatedChargedThroughput("AccumulatedChargedThroughput", this),
		AccumulatedConsumedThroughput("AccumulatedConsumedThroughput", this),
		PowerLoss("PowerLoss", this),
		Range("Range", this),
		Charging("Charging", this),
		DCDC("DCDC", this)
    {}

    /**
    * Id: attribute (string)
    * Battery Identification Number as assigned by OEM.
    *
    * This could be serial number, part number plus serial number, UUID, or any other identifier that the OEM want to use to uniquely identify the battery individual.
    *
    **/
    DataPointString Id;

    /**
    * ProductionDate: attribute (string)
    * Production date of battery in ISO8601 format, e.g. YYYY-MM-DD.
    *
    **/
    DataPointString ProductionDate;

    /**
    * IsPowerConnected: sensor
    * Indicating if the power (positive terminator) of the traction battery is connected to the powertrain.
    *
    * It might be possible to disconnect the traction battery used by an electric powertrain. This is achieved by connectors, typically one for plus and one for minus.
    *
    **/
    DataPointBoolean IsPowerConnected;

    /**
    * IsGroundConnected: sensor
    * Indicating if the ground (negative terminator) of the traction battery is connected to the powertrain.
    *
    * It might be possible to disconnect the traction battery used by an electric powertrain. This is achieved by connectors, typically one for plus and one for minus.
    *
    **/
    DataPointBoolean IsGroundConnected;

    /**
    * Temperature: branch
    * Temperature Information for the battery pack.
    *
    **/
    vehicle::powertrain::tractionbattery::Temperature Temperature;

    /**
    * GrossCapacity: attribute (uint16)
    * Gross capacity of the battery.
    *
    * Unit: kWh
    **/
    DataPointUint32 GrossCapacity;

    /**
    * NetCapacity: sensor
    * Total net capacity of the battery considering aging.
    *
    * Unit: kWh
    **/
    DataPointUint32 NetCapacity;

    /**
    * StateOfHealth: sensor
    * Calculated battery state of health at standard conditions.
    *
    * Exact formula is implementation dependent. Could be e.g. current capacity at 20 degrees Celsius divided with original capacity at the same temperature.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat StateOfHealth;

    /**
    * StateOfCharge: branch
    * Information on the state of charge of the vehicle's high voltage battery.
    *
    **/
    vehicle::powertrain::tractionbattery::StateOfCharge StateOfCharge;

    /**
    * NominalVoltage: attribute (uint16)
    * Nominal Voltage of the battery.
    *
    * Nominal voltage typically refers to voltage of fully charged battery when delivering rated capacity.
    *
    * Unit: V
    **/
    DataPointUint32 NominalVoltage;

    /**
    * MaxVoltage: attribute (uint16)
    * Max allowed voltage of the battery, e.g. during charging.
    *
    * Unit: V
    **/
    DataPointUint32 MaxVoltage;

    /**
    * CurrentVoltage: sensor
    * Current Voltage of the battery.
    *
    * Unit: V
    **/
    DataPointFloat CurrentVoltage;

    /**
    * CurrentCurrent: sensor
    * Current current flowing in/out of battery. Positive = Current flowing in to battery, e.g. during charging. Negative = Current flowing out of battery, e.g. during driving.
    *
    * Unit: A
    **/
    DataPointFloat CurrentCurrent;

    /**
    * CurrentPower: sensor
    * Current electrical energy flowing in/out of battery. Positive = Energy flowing in to battery, e.g. during charging. Negative = Energy flowing out of battery, e.g. during driving.
    *
    * Unit: W
    **/
    DataPointFloat CurrentPower;

    /**
    * AccumulatedChargedEnergy: sensor
    * The accumulated energy delivered to the battery during charging over lifetime of the battery.
    *
    * Unit: kWh
    **/
    DataPointFloat AccumulatedChargedEnergy;

    /**
    * AccumulatedConsumedEnergy: sensor
    * The accumulated energy leaving HV battery for propulsion and auxiliary loads over lifetime of the battery.
    *
    * Unit: kWh
    **/
    DataPointFloat AccumulatedConsumedEnergy;

    /**
    * AccumulatedChargedThroughput: sensor
    * The accumulated charge throughput delivered to the battery during charging over lifetime of the battery.
    *
    * Unit: Ah
    **/
    DataPointFloat AccumulatedChargedThroughput;

    /**
    * AccumulatedConsumedThroughput: sensor
    * The accumulated charge throughput leaving HV battery for propulsion and auxiliary loads over lifetime of the battery.
    *
    * Unit: Ah
    **/
    DataPointFloat AccumulatedConsumedThroughput;

    /**
    * PowerLoss: sensor
    * Electrical energy lost by power dissipation to heat inside the battery.
    *
    * Unit: W
    **/
    DataPointFloat PowerLoss;

    /**
    * Range: sensor
    * Remaining range in meters using only battery.
    *
    * Unit: m
    **/
    DataPointUint32 Range;

    /**
    * Charging: branch
    * Properties related to battery charging.
    *
    **/
    vehicle::powertrain::tractionbattery::Charging Charging;

    /**
    * DCDC: branch
    * Properties related to DC/DC converter converting high voltage (from high voltage battery) to vehicle low voltage (supply voltage, typically 12 Volts).
    *
    **/
    vehicle::powertrain::tractionbattery::DCDC DCDC;

};
} // namespace velocitas::vehicle::powertrain
#endif // VMDL_VEHICLE_POWERTRAIN_TRACTIONBATTERY_H
