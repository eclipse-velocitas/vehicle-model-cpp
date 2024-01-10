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

#ifndef VMDL_VEHICLE_CHASSIS_PARKINGBRAKE_H
#define VMDL_VEHICLE_CHASSIS_PARKINGBRAKE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis {
using ParentClass = Model;

/** ParkingBrake model. */
class ParkingBrake : public ParentClass {
public:

    ParkingBrake(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsEngaged("IsEngaged", this)
    {}

    /**
    * IsEngaged: actuator
    * Parking brake status. True = Parking Brake is Engaged. False = Parking Brake is not Engaged.
    *
    **/
    DataPointBoolean IsEngaged;

};
} // namespace velocitas::vehicle::chassis
#endif // VMDL_VEHICLE_CHASSIS_PARKINGBRAKE_H
