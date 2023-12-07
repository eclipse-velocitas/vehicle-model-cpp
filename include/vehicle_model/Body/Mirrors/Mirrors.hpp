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

#ifndef VMDL_VEHICLE_BODY_MIRRORS_H
#define VMDL_VEHICLE_BODY_MIRRORS_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Mirrors model. */
class Mirrors : public ParentClass {
public:

    Mirrors(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		Tilt("Tilt", this),
		Pan("Pan", this),
		IsHeatingOn("IsHeatingOn", this)
    {}

    /**
    * Tilt: actuator
    * Mirror tilt as a percent. 0 = Center Position. 100 = Fully Upward Position. -100 = Fully Downward Position.
    *
    * Value range: [-100, 100]
    * Unit: percent
    **/
    DataPointInt32 Tilt;

    /**
    * Pan: actuator
    * Mirror pan as a percent. 0 = Center Position. 100 = Fully Left Position. -100 = Fully Right Position.
    *
    * Value range: [-100, 100]
    * Unit: percent
    **/
    DataPointInt32 Pan;

    /**
    * IsHeatingOn: actuator
    * Mirror Heater on or off. True = Heater On. False = Heater Off.
    *
    **/
    DataPointBoolean IsHeatingOn;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_MIRRORS_H
