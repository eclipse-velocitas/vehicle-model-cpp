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

#ifndef VMDL_VEHICLE_ANGULARVELOCITY_H
#define VMDL_VEHICLE_ANGULARVELOCITY_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle {
using ParentClass = Model;

/** AngularVelocity model. */
class AngularVelocity : public ParentClass {
public:

    AngularVelocity(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Roll("Roll", this),
		Pitch("Pitch", this),
		Yaw("Yaw", this)
    {}

    /**
    * Roll: sensor
    * Vehicle rotation rate along X (longitudinal).
    *
    * Unit: degrees/s
    **/
    DataPointFloat Roll;

    /**
    * Pitch: sensor
    * Vehicle rotation rate along Y (lateral).
    *
    * Unit: degrees/s
    **/
    DataPointFloat Pitch;

    /**
    * Yaw: sensor
    * Vehicle rotation rate along Z (vertical).
    *
    * Unit: degrees/s
    **/
    DataPointFloat Yaw;

};
} // namespace velocitas::vehicle
#endif // VMDL_VEHICLE_ANGULARVELOCITY_H
