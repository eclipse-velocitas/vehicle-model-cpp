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

#ifndef VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_H
#define VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Chassis/Axle/Wheel/Brake/Brake.hpp"
#include "vehicle_model/Chassis/Axle/Wheel/Tire/Tire.hpp"

namespace velocitas::vehicle::chassis::axle {
using ParentClass = Model;

/** Wheel model. */
class Wheel : public ParentClass {
public:

    Wheel(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Brake("Brake", this),
		Tire("Tire", this),
		Speed("Speed", this)
    {}

    /**
    * Brake: branch
    * Brake signals for wheel
    *
    **/
    vehicle::chassis::axle::wheel::Brake Brake;

    /**
    * Tire: branch
    * Tire signals for wheel.
    *
    **/
    vehicle::chassis::axle::wheel::Tire Tire;

    /**
    * Speed: sensor
    * Rotational speed of a vehicle's wheel.
    *
    * Unit: km/h
    **/
    DataPointFloat Speed;

};
} // namespace velocitas::vehicle::chassis::axle
#endif // VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_H
