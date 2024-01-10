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

#ifndef VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_TIRE_H
#define VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_TIRE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::chassis::axle::wheel {
using ParentClass = Model;

/** Tire model. */
class Tire : public ParentClass {
public:

    Tire(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Pressure("Pressure", this),
		IsPressureLow("IsPressureLow", this),
		Temperature("Temperature", this)
    {}

    /**
    * Pressure: sensor
    * Tire pressure in kilo-Pascal.
    *
    * Unit: kPa
    **/
    DataPointUint32 Pressure;

    /**
    * IsPressureLow: sensor
    * Tire Pressure Status. True = Low tire pressure. False = Good tire pressure.
    *
    **/
    DataPointBoolean IsPressureLow;

    /**
    * Temperature: sensor
    * Tire temperature in Celsius.
    *
    * Unit: celsius
    **/
    DataPointFloat Temperature;

};
} // namespace velocitas::vehicle::chassis::axle::wheel
#endif // VMDL_VEHICLE_CHASSIS_AXLE_WHEEL_TIRE_H
