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

#ifndef VMDL_VEHICLE_POWERTRAIN_TRANSMISSION_H
#define VMDL_VEHICLE_POWERTRAIN_TRANSMISSION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::powertrain {
using ParentClass = Model;

/** Transmission model. */
class Transmission : public ParentClass {
public:

    Transmission(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Type("Type", this),
		GearCount("GearCount", this),
		DriveType("DriveType", this),
		TravelledDistance("TravelledDistance", this),
		CurrentGear("CurrentGear", this),
		SelectedGear("SelectedGear", this),
		IsParkLockEngaged("IsParkLockEngaged", this),
		IsLowRangeEngaged("IsLowRangeEngaged", this),
		IsElectricalPowertrainEngaged("IsElectricalPowertrainEngaged", this),
		PerformanceMode("PerformanceMode", this),
		GearChangeMode("GearChangeMode", this),
		Temperature("Temperature", this),
		ClutchEngagement("ClutchEngagement", this),
		ClutchWear("ClutchWear", this),
		DiffLockFrontEngagement("DiffLockFrontEngagement", this),
		DiffLockRearEngagement("DiffLockRearEngagement", this),
		TorqueDistribution("TorqueDistribution", this)
    {}

    /**
    * Type: attribute (string)
    * Transmission type.
    *
    * Allowed values: UNKNOWN, SEQUENTIAL, H, AUTOMATIC, DSG, CVT
    **/
    DataPointString Type;

    /**
    * GearCount: attribute (int8)
    * Number of forward gears in the transmission. -1 = CVT.
    *
    **/
    DataPointInt32 GearCount;

    /**
    * DriveType: attribute (string)
    * Drive type.
    *
    * Allowed values: UNKNOWN, FORWARD_WHEEL_DRIVE, REAR_WHEEL_DRIVE, ALL_WHEEL_DRIVE
    **/
    DataPointString DriveType;

    /**
    * TravelledDistance: sensor
    * Odometer reading, total distance travelled during the lifetime of the transmission.
    *
    * Unit: km
    **/
    DataPointFloat TravelledDistance;

    /**
    * CurrentGear: sensor
    * The current gear. 0=Neutral, 1/2/..=Forward, -1/-2/..=Reverse.
    *
    **/
    DataPointInt32 CurrentGear;

    /**
    * SelectedGear: actuator
    * The selected gear. 0=Neutral, 1/2/..=Forward, -1/-2/..=Reverse, 126=Park, 127=Drive.
    *
    **/
    DataPointInt32 SelectedGear;

    /**
    * IsParkLockEngaged: actuator
    * Is the transmission park lock engaged or not. False = Disengaged. True = Engaged.
    *
    **/
    DataPointBoolean IsParkLockEngaged;

    /**
    * IsLowRangeEngaged: actuator
    * Is gearbox in low range mode or not. False = Normal/High range engaged. True = Low range engaged.
    *
    * The possibility to switch between low and high gear range is typically only available in heavy vehicles and off-road vehicles.
    *
    **/
    DataPointBoolean IsLowRangeEngaged;

    /**
    * IsElectricalPowertrainEngaged: actuator
    * Is electrical powertrain mechanically connected/engaged to the drivetrain or not. False = Disconnected/Disengaged. True = Connected/Engaged.
    *
    * In some hybrid solutions it is possible to disconnect/disengage the electrical powertrain mechanically to avoid induced voltage reaching a too high level when driving at high speed.
    *
    **/
    DataPointBoolean IsElectricalPowertrainEngaged;

    /**
    * PerformanceMode: actuator
    * Current gearbox performance mode.
    *
    * Allowed values: NORMAL, SPORT, ECONOMY, SNOW, RAIN
    **/
    DataPointString PerformanceMode;

    /**
    * GearChangeMode: actuator
    * Is the gearbox in automatic or manual (paddle) mode.
    *
    * Allowed values: MANUAL, AUTOMATIC
    **/
    DataPointString GearChangeMode;

    /**
    * Temperature: sensor
    * The current gearbox temperature.
    *
    * Unit: celsius
    **/
    DataPointInt32 Temperature;

    /**
    * ClutchEngagement: actuator
    * Clutch engagement. 0% = Clutch fully disengaged. 100% = Clutch fully engaged.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat ClutchEngagement;

    /**
    * ClutchWear: sensor
    * Clutch wear as a percent. 0 = no wear. 100 = worn.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 ClutchWear;

    /**
    * DiffLockFrontEngagement: actuator
    * Front Diff Lock engagement. 0% = Diff lock fully disengaged. 100% = Diff lock fully engaged.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat DiffLockFrontEngagement;

    /**
    * DiffLockRearEngagement: actuator
    * Rear Diff Lock engagement. 0% = Diff lock fully disengaged. 100% = Diff lock fully engaged.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointFloat DiffLockRearEngagement;

    /**
    * TorqueDistribution: actuator
    * Torque distribution between front and rear axle in percent. -100% = Full torque to front axle, 0% = 50:50 Front/Rear, 100% = Full torque to rear axle.
    *
    * Value range: [-100, 100]
    * Unit: percent
    **/
    DataPointFloat TorqueDistribution;

};
} // namespace velocitas::vehicle::powertrain
#endif // VMDL_VEHICLE_POWERTRAIN_TRANSMISSION_H
