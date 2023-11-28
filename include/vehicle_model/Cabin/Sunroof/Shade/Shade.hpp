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

#ifndef VMDL_VEHICLE_CABIN_SUNROOF_SHADE_H
#define VMDL_VEHICLE_CABIN_SUNROOF_SHADE_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::sunroof {
using ParentClass = Model;

/** Shade model. */
class Shade : public ParentClass {
public:

    Shade(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Switch("Switch", this),
		Position("Position", this)
    {}

    /**
    * Switch: actuator
    * Switch controlling sliding action such as window, sunroof, or blind.
    *
    * Allowed values: INACTIVE, CLOSE, OPEN, ONE_SHOT_CLOSE, ONE_SHOT_OPEN
    **/
    DataPointString Switch;

    /**
    * Position: actuator
    * Position of window blind. 0 = Fully retracted. 100 = Fully deployed.
    *
    * Value range: [0, 100]
    * Unit: percent
    **/
    DataPointUint32 Position;

};
} // namespace velocitas::vehicle::cabin::sunroof
#endif // VMDL_VEHICLE_CABIN_SUNROOF_SHADE_H
