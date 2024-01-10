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

#ifndef VMDL_VEHICLE_CABIN_LIGHTS_SPOTLIGHT_H
#define VMDL_VEHICLE_CABIN_LIGHTS_SPOTLIGHT_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::cabin::lights {
using ParentClass = Model;

/** Spotlight model. */
class Spotlight : public ParentClass {
public:

    Spotlight(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsSharedOn("IsSharedOn", this),
		IsLeftOn("IsLeftOn", this),
		IsRightOn("IsRightOn", this)
    {}

    /**
    * IsSharedOn: sensor
    * Is a shared light across a specific row on
    *
    **/
    DataPointBoolean IsSharedOn;

    /**
    * IsLeftOn: actuator
    * Is light on the left side switched on
    *
    **/
    DataPointBoolean IsLeftOn;

    /**
    * IsRightOn: actuator
    * Is light on the right side switched on
    *
    **/
    DataPointBoolean IsRightOn;

};
} // namespace velocitas::vehicle::cabin::lights
#endif // VMDL_VEHICLE_CABIN_LIGHTS_SPOTLIGHT_H
