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

#ifndef VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_BRAKE_H
#define VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_BRAKE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis::axle::wheel {
using ParentClass = Model;

/** Brake model. */
class Brake : public ParentClass {
public:

    Brake(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		FluidLevel("FluidLevel", this),
		IsFluidLevelLow("IsFluidLevelLow", this),
		PadWear("PadWear", this),
		IsBrakesWorn("IsBrakesWorn", this)
    {}

    /**
    * FluidLevel: sensor
    * Brake fluid level as percent. 0 = Empty. 100 = Full.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 FluidLevel;

    /**
    * IsFluidLevelLow: sensor
    * Brake fluid level status. True = Brake fluid level low. False = Brake fluid level OK.
    *
    **/
    DataPointBoolean IsFluidLevelLow;

    /**
    * PadWear: sensor
    * Brake pad wear as percent. 0 = No Wear. 100 = Worn.
    *
    * Value range: [, 100]
    * Unit: percent
    **/
    DataPointUint32 PadWear;

    /**
    * IsBrakesWorn: sensor
    * Brake pad wear status. True = Worn. False = Not Worn.
    *
    **/
    DataPointBoolean IsBrakesWorn;

};
} // namespace velocitas::vehicle::chassis::axle::wheel
#endif // VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_BRAKE_H
