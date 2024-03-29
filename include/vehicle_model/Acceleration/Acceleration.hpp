/**
 * Copyright (c) 2022-2023 Contributors to the Eclipse Foundation
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
#ifndef VMDL_VEHICLE_ACCELERATION_H
#define VMDL_VEHICLE_ACCELERATION_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** Acceleration model. */
class Acceleration : public ParentClass {
public:

    Acceleration(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Longitudinal("Longitudinal", this),
		Lateral("Lateral", this),
		Vertical("Vertical", this)
    {}

    /**
    * Longitudinal: sensor
    * Vehicle acceleration in X (longitudinal acceleration).
    *
    * Unit: m/s^2
    **/
    DataPointFloat Longitudinal;

    /**
    * Lateral: sensor
    * Vehicle acceleration in Y (lateral acceleration).
    *
    * Unit: m/s^2
    **/
    DataPointFloat Lateral;

    /**
    * Vertical: sensor
    * Vehicle acceleration in Z (vertical acceleration).
    *
    * Unit: m/s^2
    **/
    DataPointFloat Vertical;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_ACCELERATION_H
