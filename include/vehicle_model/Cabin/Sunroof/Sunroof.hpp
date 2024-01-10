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

#ifndef VMDL_VEHICLE_CABIN_SUNROOF_H
#define VMDL_VEHICLE_CABIN_SUNROOF_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

#include "vehicle_model/Cabin/Sunroof/Shade/Shade.hpp"

namespace velocitas::vehicle::cabin {
using ParentClass = Model;

/** Sunroof model. */
class Sunroof : public ParentClass {
public:

    Sunroof(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Position("Position", this),
		Switch("Switch", this),
		Shade("Shade", this)
    {}

    /**
    * Position: sensor
    * Sunroof position. 0 = Fully closed 100 = Fully opened. -100 = Fully tilted.
    *
    * Value range: [-100, 100]
    **/
    DataPointInt32 Position;

    /**
    * Switch: actuator
    * Switch controlling sliding action such as window, sunroof, or shade.
    *
    * Allowed values: INACTIVE, CLOSE, OPEN, ONE_SHOT_CLOSE, ONE_SHOT_OPEN, TILT_UP, TILT_DOWN
    **/
    DataPointString Switch;

    /**
    * Shade: branch
    * Sun roof shade status.
    *
    **/
    vehicle::cabin::sunroof::Shade Shade;

};
} // namespace velocitas::vehicle::cabin
#endif // VMDL_VEHICLE_CABIN_SUNROOF_H
