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

#ifndef VMDL_VEHICLE_BODY_TRUNK_H
#define VMDL_VEHICLE_BODY_TRUNK_H

#include "sdk/DataPoint.h"
#include "sdk/Model.h"

namespace velocitas::vehicle::body {
using ParentClass = Model;

/** Trunk model. */
class Trunk : public ParentClass {
public:

    Trunk(const std::string& name, ParentClass* parent) :
        ParentClass(name, parent),
		IsOpen("IsOpen", this),
		IsLocked("IsLocked", this)
    {}

    /**
    * IsOpen: actuator
    * Trunk open or closed. True = Open. False = Closed.
    *
    **/
    DataPointBoolean IsOpen;

    /**
    * IsLocked: actuator
    * Is trunk locked or unlocked. True = Locked. False = Unlocked.
    *
    **/
    DataPointBoolean IsLocked;

};
} // namespace velocitas::vehicle::body
#endif // VMDL_VEHICLE_BODY_TRUNK_H
